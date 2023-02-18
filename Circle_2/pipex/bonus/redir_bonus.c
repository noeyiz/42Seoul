/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:45:59 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/18 23:47:08 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_child_dup2(t_info *info, int is_odd)
{
	if (is_odd)
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

static void	ft_parent_dup2(t_info *info, int is_odd)
{
	if (is_odd)
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

void	ft_execute_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	*file;

	argv = ft_get_cmd_argv(cmd);
	file = ft_get_cmd_file(argv[0], envp);
	if (file == NULL)
		ft_exit("command not found", EXIT_COMMAND_NOT_FOUND);
	execve(file, argv, envp);
}

void	ft_redir_xx(t_info *info, char *cmd, int is_odd)
{
	if (is_odd)
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
		ft_child_dup2(info, is_odd);
		ft_execute_cmd(cmd, info->envp);
	}
	else
	{
		waitpid(info->pid, NULL, 0);
		ft_parent_dup2(info, is_odd);
	}
}
