/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:30:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 15:12:02 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strncmp() function lexicographically compares the null-terminated
 * strings s1 and s2.  The strncmp() function compares not more than n
 * characters. Because strncmp() is designed for comparing strings rather than 
 * binary data, characters that appear after a ‘\0’ character are not compared.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	while (--n && *s1_ptr && *s2_ptr && *s1_ptr == *s2_ptr)
	{
		s1_ptr++;
		s2_ptr++;
	}
	return (*s1_ptr - *s2_ptr);
}
