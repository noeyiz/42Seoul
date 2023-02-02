/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:00:31 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/02 20:41:44 by jikoo            ###   ########.fr       */
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

typedef struct s_command
{
	char	*file;
	char	**argv;
}	t_command;

typedef struct s_info
{
	int			fd_infile;
	int			fd_outfile;
	int			fd_pipe[2];
	char		**envp;
	t_command	*command;
	pid_t 		pid;
}	t_info;

#endif