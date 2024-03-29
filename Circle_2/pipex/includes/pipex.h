/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:00:31 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/18 23:51:14 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"

# define EXIT_COMMAND_NOT_FOUND 127

typedef struct s_info
{
	int		pipe_fd[2];
	char	**envp;
	pid_t	pid;
}	t_info;

char	**ft_get_cmd_argv(char *str);
char	*ft_get_cmd_file(char *cmd, char **envps);

#endif