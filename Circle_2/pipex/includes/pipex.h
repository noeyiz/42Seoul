/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:00:31 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/31 17:04:02 by jikoo            ###   ########.fr       */
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

typedef struct s_info
{
    char    **envp;
    int     fd_infile;
    int     fd_outfile;
}   t_info;

/* args */
void	ft_parse_args(t_info *info, char **argv, char **envp);

/* utils */
void	ft_exit(char *message, int type);

#endif