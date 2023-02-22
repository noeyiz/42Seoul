/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:11:38 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/22 17:10:47 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_execute_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	*file;

	argv = ft_get_cmd_argv(cmd);
	file = ft_get_cmd_file(argv[0], envp);
	if (file == NULL)
		ft_exit("command not found", EXIT_COMMAND_NOT_FOUND);
	execve(file, argv, envp);
	ft_exit("execve failure", EXIT_FAILURE);
}

static void	ft_child_dup2(t_info *info, int cnt)
{
	if (cnt % 2)
	{
		dup2(info->pipe_odd[1], STDOUT_FILENO);
		close(info->pipe_odd[0]);
	}
	else
	{
		dup2(info->pipe_even[1], STDOUT_FILENO);
		close(info->pipe_even[0]);
	}
}

static void	ft_parent_dup2(t_info *info, int cnt)
{
	if (cnt % 2)
	{
		dup2(info->pipe_odd[0], STDIN_FILENO);
		close(info->pipe_odd[1]);
		if (info->pipe_even[0] > -1)
			close(info->pipe_even[0]);
	}
	else
	{
		dup2(info->pipe_even[0], STDIN_FILENO);
		close(info->pipe_even[1]);
		if (info->pipe_odd[0] > -1)
			close(info->pipe_odd[0]);
	}
}

void	ft_pipe_to_pipe(t_info *info, char *cmd, int cnt)
{
	if (cnt % 2)
	{
		if (pipe(info->pipe_odd) < 0)
			ft_exit("pipe", EXIT_FAILURE);
	}
	else
	{
		if (pipe(info->pipe_even) < 0)
			ft_exit("pipe", EXIT_FAILURE);
	}
	info->pid = fork();
	if (info->pid < 0)
		ft_exit("fork", EXIT_FAILURE);
	else if (info->pid == 0)
	{
		ft_child_dup2(info, cnt);
		ft_execute_cmd(cmd, info->envp);
	}
	else
	{
		waitpid(info->pid, NULL, 0);
		ft_parent_dup2(info, cnt);
	}
}
