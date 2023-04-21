/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:42 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:45 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	execute_single_cmd_child(t_info *info, t_cmd *cmd_list)
{
	char	*file;

	if (set_redirection_fd(cmd_list, 0) == -1)
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

void	execute_single_cmd(t_info *info, t_cmd *cmd_list)
{
	pid_t	pid;

	if (!check_builtin(info, cmd_list, 0))
	{
		pid = fork();
		if (pid < 0)
			ms_error("fork", NULL);
		else if (pid == 0)
		{
			signal(SIGINT, quit_handler);
			signal(SIGQUIT, quit_handler);
			execute_single_cmd_child(info, cmd_list);
		}
		else
		{
			signal(SIGINT, SIG_IGN);
			wait(&(g_exit_status));
			if (WIFSIGNALED(g_exit_status))
				g_exit_status = 128 + WTERMSIG(g_exit_status);
			if (WIFEXITED(g_exit_status))
				g_exit_status = WEXITSTATUS(g_exit_status);
		}
	}
}
