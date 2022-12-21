/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:19 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/22 00:22:35 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

int		ft_find_nextline(char *str);
int		ft_gnl_strlen(char *str);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_strldup(char *str, int start, int len);

#endif
