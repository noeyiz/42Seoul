/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:24 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/14 21:26:19 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exit(char *message, int status)
{
	perror(message);
	exit(status);
}

int	ft_check_heredoc(t_info *info, char *str)
{
	if (str && ft_strncmp(str, "here_doc", ft_strlen(str)) == 0)
		info->is_heredoc = 1;
	else
		info->is_heredoc = 0;
	return (info->is_heredoc);
}

char	**ft_get_envp(char **envp)
{
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	return (ft_split(*envp + 5, ':'));
}

int	ft_heredoc(char *filename, char *limiter)
{
	int		fd;
	char	*input;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
		if (ft_strlen(input) == ft_strlen(limiter) && \
		ft_strncmp(input, limiter, ft_strlen(input)) == 0)
			break ;
		write(fd, input, ft_strlen(input));
		free(input);
	}
	close(fd);
	free(limiter);
	free(input);
	return (open(filename, O_RDONLY));
}

void	ft_set_infile_fd(t_info *info, char **argv)
{
	if (info->is_heredoc)
		info->infile_fd = ft_heredoc(argv[1], argv[2]);
	else
		info->infile_fd = open(argv[1], O_RDONLY);
	if (info->infile_fd < 0)
		ft_exit(argv[1], EXIT_FAILURE);
}

void	ft_set_outfile_fd(t_info *info, char *filename)
{
	if (info->is_heredoc)
		info->outfile_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		info->outfile_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
		ft_exit(filename, EXIT_FAILURE);
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

static char	*ft_join_params(char **params, int idx)
{
	char	*join;
	char	*temp;

	join = ft_strdup("");
	while (params[idx])
	{
		temp = ft_strjoin_with_space(join, params[idx]);
		free(join);
		join = temp;
		idx++;
	}
	temp = ft_substr(join, 2, ft_strlen(join) - 3);
	free(join);
	join = temp;
	return (join);
}

char	**ft_get_cmd_argv(char *str)
{
	int		i;
	int		awk_sed_flag;
	char	**cmd_argv;

	cmd_argv = ft_split(str, ' ');
	awk_sed_flag = 0;
	i = -1;
	while (cmd_argv[++i])
	{
		if (cmd_argv[i][0] == '\'' || cmd_argv[i][0] == '\"')
		{
			awk_sed_flag = 1;
			break ;
		}
	}
	if (awk_sed_flag)
	{
		cmd_argv[i] = ft_join_params(cmd_argv, i);
		cmd_argv[++i] = NULL;
	}
	return (cmd_argv);
}

char	*ft_get_cmd_file(char *cmd, char **envps)
{
	char	*cmd_file;
	char	*slash_cmd;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	slash_cmd = ft_strjoin("/", cmd);
	while (*envps)
	{
		cmd_file = ft_strjoin(*envps, slash_cmd);
		if (access(cmd_file, X_OK) == 0)
		{
			free(slash_cmd);
			return (cmd_file);
		}
		free(cmd_file);
		envps++;
	}
	free(slash_cmd);
	return (NULL);
}

void	ft_execute_cmd(t_info *info, int cnt, char *cmd)
{
	char	**argv;
	char	*file;

	// 여기에서 fd만 잘 설정해주면 된다 . . . 아마도 !!! 💞
	if (cnt == 0) // 처음
		// infile_fd, pipe_even[1]
	else if (cnt == info->num_of_cmds - 1) // 마지막
		// pipe_??[0], outfile_fd
	else // 중간
		// pipe_??[0], pipe_??[1]
	argv = ft_get_cmd_argv(cmd);
	file = ft_get_cmd_file(argv[0], info->envp);
	if (file == NULL)
		ft_exit("command not found", EXIT_COMMAND_NOT_FOUND);
	execve(file, argv, info->envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		cnt;
	t_info	info;

	if (argc < 5 + ft_check_heredoc(&info, argv[1]))
		ft_exit("invalid parameters", EXIT_FAILURE);
	// 초기값 설정
	ft_set_infile_fd(&info, argv);
	ft_set_outfile_fd(&info, argv[argc - 1]);
	info.num_of_cmds = argc - 3 - info.is_heredoc;
	info.envp = ft_get_envp(envp);
	if (pipe(info.pipe_odd) < 0 || pipe(info.pipe_even) < 0)
		ft_exit("pipe", EXIT_FAILURE);
	// 요기까지..?
	cnt = 0;
	while (cnt < info.num_of_cmds)
	{
		ft_execute_cmd(&info, cnt, argv[2 + info.is_heredoc + cnt]);
		waitpid(info.pid, NULL, 0);
		cnt++;
	}
	exit(EXIT_SUCCESS);
}
