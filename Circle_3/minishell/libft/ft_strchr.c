/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:41:17 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:24:03 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strchr() function locates the first occurrence of c (converted to a
 * char) in the string pointed to by s.  The terminating null character is
 * considered to be part of the string; therefore if c is ‘\0’, the functions
 * locate the terminating ‘\0’.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((char *)s);
}
