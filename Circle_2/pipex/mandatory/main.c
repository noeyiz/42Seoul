/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:01:56 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/07 21:06:58 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 0 : 성공
// 1 : 일반적인 에러
// 127 : command not found

#include "../includes/pipex.h"

void	ft_exit(char *message, int status)
{
	perror(message);
	exit(status);
}

static char	*ft_strjoin_with_space(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len + 2));
	if (join == NULL)
		return (NULL);
	idx = 0;
	while (*s1)
		join[idx++] = *s1++;
	join[idx++] = ' ';
	while (*s2)
		join[idx++] = *s2++;
	join[idx] = '\0';
	return (join);
}

char	*ft_join_params(char **params, int idx)
{
	char	*result;
	char	*temp;
	
	result = ft_strdup("");
	while (params[idx])
	{
		temp = ft_strjoin_with_space(result, params[idx]);
		free(result);
		result = temp;
		idx++;
	}
	temp = ft_substr(result, 2, ft_strlen(result) - 3);
	free(result);
	result = temp;
	return(result);
}

char	**ft_get_argv(char *str)
{
	int		i;
	int		awk_sed_flag;
	char	**result;

	result = ft_split(str, ' ');
	awk_sed_flag = 0;
	i = -1;
	while (result[++i])
	{
		if (result[i][0] == '\'' || result[i][0] == '\"')
		{
			awk_sed_flag = 1;
			break ;
		}
	}
	if (awk_sed_flag)
	{
		result[i] = ft_join_params(result, i);
		result[++i] = NULL;
	}
	return (result);
}

char	*ft_get_filename(char *cmd, char **envps)
{
	char	*result;
	char	*slash_cmd;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	slash_cmd = ft_strjoin("/", cmd);
	while (*envps)
	{
		result = ft_strjoin(*envps, slash_cmd);
		if (access(result, X_OK) == 0)
		{
			free(slash_cmd);
			return (result);
		}
		free(result);
		envps++;
	}
	free(slash_cmd);
	return (NULL);
}

void	ft_execute_command_child(t_info *info, char **args)
{
	int		infile_fd;
	char	**argv;
	char	*file;

	infile_fd = open(args[1], O_RDONLY);
	if (infile_fd < 0)
		ft_exit("infile", EXIT_FAILURE);
	close(info->pipe_fd[0]);
	dup2(infile_fd, STDIN_FILENO);
	dup2(info->pipe_fd[1], STDOUT_FILENO);
	argv = ft_get_argv(args[2]);
	file = ft_get_filename(argv[0], info->envp);
	if (file == NULL)
		ft_exit("command not found", 127);
	execve(file, argv, info->envp);
	ft_exit("execve failure", EXIT_FAILURE);
}

void	ft_execute_command_parent(t_info *info, char **args)
{
	int		outfile_fd;
	char	**argv;
	char	*file;
	
	outfile_fd = open(args[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		ft_exit("outfile", EXIT_FAILURE);
	close(info->pipe_fd[1]);
	dup2(info->pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	argv = ft_get_argv(args[3]);
	file = ft_get_filename(argv[0], info->envp);
	if (file == NULL)
		ft_exit("command not found", 127);
	execve(file, argv, info->envp);
	ft_exit("execve failure", EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		status;

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
		ft_execute_command_child(&info, argv);
	if (info.pid > 0)
	{
		waitpid(info.pid, &status, 0);
		ft_execute_command_parent(&info, argv);
	}
	exit(WEXITSTATUS(status));
}
