/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:52 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/18 23:50:07 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_init_info(t_info *info, int argc, char **envp)
{
	info->num_of_cmds = argc - 3 - info->is_heredoc;
	info->pipe_even[0] = -1;
	info->pipe_even[1] = -1;
	info->pipe_odd[0] = -1;
	info->pipe_odd[1] = -1;
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	info->envp = ft_split(*envp + 5, ':');
}

static void	ft_heredoc(char *filename, char *limiter)
{
	int		fd;
	char	*input;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_exit(filename, EXIT_FAILURE);
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
}

static void	ft_set_infile_fd(t_info *info, char **argv)
{
	if (info->is_heredoc)
		ft_heredoc(argv[1], argv[2]);
	info->infile_fd = open(argv[1], O_RDONLY);
	if (info->infile_fd < 0)
		ft_exit(argv[1], EXIT_FAILURE);
	if (info->infile_fd < 0)
		ft_exit(argv[1], EXIT_FAILURE);
	dup2(info->infile_fd, STDIN_FILENO);
}

static void	ft_set_outfile_fd(t_info *info, char **argv, int idx)
{
	if (info->is_heredoc)
	{
		unlink(argv[1]);
		info->outfile_fd = open(argv[idx], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
		info->outfile_fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
		ft_exit(argv[idx], EXIT_FAILURE);
	dup2(info->outfile_fd, STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int		cnt;
	t_info	info;

	if (argc < 5 + ft_check_heredoc(&info, argv[1]))
		ft_exit("invalid parameters", EXIT_FAILURE);
	ft_init_info(&info, argc, envp);
	ft_set_infile_fd(&info, argv);
	cnt = -1;
	while (++cnt < info.num_of_cmds - 1)
		ft_redir_xx(&info, argv[2 + info.is_heredoc + cnt], cnt % 2);
	ft_set_outfile_fd(&info, argv, argc - 1);
	ft_execute_cmd(argv[argc - 2], info.envp);
	exit(EXIT_SUCCESS);
}
