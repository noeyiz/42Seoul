/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:01:56 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/10 20:41:17 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_exit(char *message, int status)
{
	perror(message);
	exit(status);
}

static void	ft_execute_cmd_child(t_info *info, char *filename, char *cmd)
{
	int		infile_fd;
	char	**argv;
	char	*file;

	infile_fd = open(filename, O_RDONLY);
	if (infile_fd < 0)
		ft_exit(filename, EXIT_FAILURE);
	close(info->pipe_fd[0]);
	dup2(infile_fd, STDIN_FILENO);
	dup2(info->pipe_fd[1], STDOUT_FILENO);
	argv = ft_get_cmd_argv(cmd);
	file = ft_get_cmd_file(argv[0], info->envp);
	if (file == NULL)
		ft_exit("command not found", EXIT_COMMAND_NOT_FOUND);
	execve(file, argv, info->envp);
	ft_exit("execve failure", EXIT_FAILURE);
}

static void	ft_execute_cmd_parent(t_info *info, char *filename, char *cmd)
{
	int		outfile_fd;
	char	**argv;
	char	*file;

	outfile_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		ft_exit(filename, EXIT_FAILURE);
	close(info->pipe_fd[1]);
	dup2(info->pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	argv = ft_get_cmd_argv(cmd);
	file = ft_get_cmd_file(argv[0], info->envp);
	if (file == NULL)
		ft_exit("command not found", EXIT_COMMAND_NOT_FOUND);
	execve(file, argv, info->envp);
	ft_exit("execve", EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
		ft_exit("invalid parameters", EXIT_FAILURE);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	info.envp = ft_split(*envp + 5, ':');
	if (pipe(info.pipe_fd) < 0)
		ft_exit("pipe", EXIT_FAILURE);
	info.pid = fork();
	if (info.pid < 0)
		ft_exit("fork", EXIT_FAILURE);
	if (info.pid == 0)
		ft_execute_cmd_child(&info, argv[1], argv[2]);
	waitpid(info.pid, NULL, 0);
	ft_execute_cmd_parent(&info, argv[4], argv[3]);
	ft_exit("execve", EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
