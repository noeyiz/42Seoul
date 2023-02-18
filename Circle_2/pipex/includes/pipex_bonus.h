/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:58 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/18 23:49:01 by jikoo            ###   ########.fr       */
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

/* cmd_bonus.c */
char	**ft_get_cmd_argv(char *str);
char	*ft_get_cmd_file(char *cmd, char **envps);

/* redir_bonus.c */
void	ft_execute_cmd(char *cmd, char **envp);
void	ft_redir_xx(t_info *info, char *cmd, int is_odd);

/* util_bonus.c */
void	ft_exit(char *message, int status);
int		ft_check_heredoc(t_info *info, char *str);

#endif