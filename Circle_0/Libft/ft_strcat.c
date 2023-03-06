/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:21:33 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:24:00 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strcat() function appends a copy of the null-terminated string s2 
 * to the end of the null-terminated string s1, then adds a terminating ‘\0’.
 * The string s1 must have sufficient space to hold the result.  The source
 * and destination strings should not overlap, as the behavior is undefined.
 */
char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char		*s1_ptr;
	const char	*s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;
	while (*s1_ptr)
		s1_ptr++;
	while (*s2_ptr)
		*s1_ptr++ = *s2_ptr++;
	*s1_ptr = '\0';
	return (s1);
}
