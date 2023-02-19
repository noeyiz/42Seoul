/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:58 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/19 18:43:30 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define EXIT_COMMAND_NOT_FOUND 127

typedef struct s_info
{
	int		is_heredoc;
	int		infile_fd;
	int		outfile_fd;
	int		num_of_cmds;
	int		pipe_odd[2];
	int		pipe_even[2];
	char	**envp;
	pid_t	pid;
}	t_info;

void	ft_exit(char *message, int status);

/* io_fd */
void	ft_set_infile_fd(t_info *info, char **argv);
void	ft_set_outfile_fd(t_info *info, char **argv, int idx);

/* cmd_ */
char	**ft_get_cmd_argv(char *str);
char	*ft_get_cmd_file(char *cmd, char **envps);

/* execute */
void	ft_execute_cmd(char *cmd, char **envp);
void	ft_pipe_to_pipe(t_info *info, char *cmd, int is_odd);

#endif