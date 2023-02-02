/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:38:08 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/02 21:19:12 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(char *message, int type)
{
	if (type)
		perror(message);
	else
		ft_putstr_fd(message, 2);
	exit(1);
}

void	ft_set_io_fd(t_info *info, char **argv)
{
	info->fd_infile = open(argv[1], O_RDONLY);
	if (info->fd_infile < 0)
		ft_exit("infile", 1);
	info->fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->fd_outfile < 0)
		ft_exit("outfile", 1);
}

void	ft_set_envp(t_info *info, char **envp)
{
	char	*path;

	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = *envp + 5;
	info->envp = ft_split(path, ':');
}

char	*ft_get_path_command(t_info *info, char *cmd)
{
	int		i;
	char	*temp;
	char	*command;

	temp = ft_strjoin("/", cmd);
	if (temp == NULL)
		ft_exit(NULL, 0);
	i = 0;
	while (info->envp[i])
	{
		command = ft_strjoin(info->envp[i], temp);
		if (command == NULL)
			ft_exit(NULL, 0);
		if (access(command, X_OK) == 0)
		{
			free(temp);
			return (command);
		}
		free(command);
		i++;
	}
	free(temp);
	return (NULL);
}

void	ft_set_command(t_info *info, char **argv)
{
	int	i;

	info->command = (t_command *)malloc(sizeof(t_command) * 2);
	if (info->command == NULL)
		ft_exit(NULL, 0);
	i = 0;
	while (i < 2)
	{
		info->command[i].argv = ft_split(argv[i + 2], ' ');
		if (info->command[i].argv == NULL)
			ft_exit(NULL, 0);
		info->command[i].file = ft_get_path_command(info, \
		info->command[i].argv[0]);
		if (info->command[i].file == NULL)
			ft_exit(NULL, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
		ft_exit("Invalid number of arguments!\n", 0);
	ft_set_io_fd(&info, argv);
	ft_set_envp(&info, envp);
	ft_set_command(&info, argv);
	if (pipe(info.fd_pipe) < 0)
		ft_exit("pipe error", 1);
	info.pid = fork();
	if (info.pid < 0)
		ft_exit("fork error", 1);
	else if (info.pid == 0)
	{
		if (dup2(info.fd_infile, STDIN_FILENO) < 0)
			ft_exit("dup2 error", 1);
		if (dup2(info.fd_pipe[1], STDOUT_FILENO) < 0)
			ft_exit("dup2 error", 1);
		close(info.fd_pipe[0]);
		close(info.fd_pipe[1]);
		close(info.fd_infile);
		if (execve(info.command[0].file, info.command[0].argv, info.envp) < 0)
			ft_exit("execve error", 1);
	}
	else
	{
		if (dup2(info.fd_pipe[0], STDIN_FILENO) < 0)
			ft_exit("dup2 error", 1);
		if (dup2(info.fd_outfile, STDOUT_FILENO) < 0)
			ft_exit("dup2 error", 1);
		close(info.fd_pipe[0]);
		close(info.fd_pipe[1]);
		close(info.fd_outfile);
		waitpid(info.pid, NULL, WNOHANG);
		if (execve(info.command[1].file, info.command[1].argv, info.envp) < 0)
			ft_exit("execve error", 1);
	}
	return (0);
}
