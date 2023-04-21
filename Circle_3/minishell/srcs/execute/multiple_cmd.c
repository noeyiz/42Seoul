/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:36 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:43 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	set_io_fd(t_cmd *cmd_list)
{
	if (cmd_list->prev && dup2(cmd_list->prev->pipe[0], STDIN_FILENO) == -1)
	{
		g_exit_status = 1;
		exit(g_exit_status);
	}
	if (cmd_list->next)
	{
		close(cmd_list->pipe[0]);
		if (dup2(cmd_list->pipe[1], STDOUT_FILENO) == -1)
		{
			g_exit_status = 1;
			exit(g_exit_status);
		}
	}
}

static void	execute_multiple_cmd_child(t_info *info, t_cmd *cmd_list, int cnt)
{
	char	*file;

	signal(SIGINT, quit_handler);
	signal(SIGQUIT, quit_handler);
	set_io_fd(cmd_list);
	if (check_builtin(info, cmd_list, cnt))
		exit(g_exit_status);
	else
	{
		if (set_redirection_fd(cmd_list, cnt) == -1)
		{
			g_exit_status = 1;
			exit(g_exit_status);
		}
		if (cmd_list->argv == NULL)
			exit(g_exit_status);
		file = get_cmd_file(cmd_list->argv[0], info->path_list);
		if (file == NULL)
			print_command_not_found(info->path_list, cmd_list->argv[0]);
		execve(file, cmd_list->argv, env_list_to_envp(info->env_list));
		ms_error("execve", NULL);
		g_exit_status = 1;
		exit(g_exit_status);
	}
}

static void	wait_and_set_exit_status(pid_t pid, int cnt)
{
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &g_exit_status, 0);
	while (--cnt)
		wait(0);
	if (WIFSIGNALED(g_exit_status))
		g_exit_status = 128 + WTERMSIG(g_exit_status);
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
}

void	execute_multiple_cmd(t_info *info, t_cmd *cmd_list)
{
	int		cnt;
	pid_t	pid;

	cnt = 0;
	while (cmd_list)
	{
		if (cmd_list->next && pipe(cmd_list->pipe) == -1)
		{
			ms_error("pipe", NULL);
			return ;
		}
		if (cmd_list->prev)
			close(cmd_list->prev->pipe[1]);
		pid = fork();
		if (pid < 0)
			ms_error("fork", NULL);
		else if (pid == 0)
			execute_multiple_cmd_child(info, cmd_list, cnt);
		if (cmd_list->prev)
			close(cmd_list->prev->pipe[0]);
		cmd_list = cmd_list->next;
		cnt++;
	}
	wait_and_set_exit_status(pid, cnt);
}
