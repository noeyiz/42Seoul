/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:52 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/21 15:03:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exit(char *message, int status)
{
	perror(message);
	exit(status);
}

static int	ft_check_heredoc(t_info *info, char *str)
{
	if (str && ft_strncmp(str, "here_doc", ft_strlen(str)) == 0)
		info->is_heredoc = 1;
	else
		info->is_heredoc = 0;
	return (info->is_heredoc);
}

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
		ft_pipe_to_pipe(&info, argv[2 + info.is_heredoc + cnt], cnt);
	ft_set_outfile_fd(&info, argv, argc - 1);
	ft_execute_cmd(argv[argc - 2], info.envp);
	exit(EXIT_SUCCESS);
}
