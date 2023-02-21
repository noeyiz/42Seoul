/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_fd_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:25:36 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/21 15:12:10 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

void	ft_set_infile_fd(t_info *info, char **argv)
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

void	ft_set_outfile_fd(t_info *info, char **argv, int idx)
{
	if (info->is_heredoc)
	{
		unlink(argv[1]);
		info->outfile_fd = open(argv[idx], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
		info->outfile_fd = open(argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
		ft_exit(argv[idx], EXIT_FAILURE);
	dup2(info->outfile_fd, STDOUT_FILENO);
}
