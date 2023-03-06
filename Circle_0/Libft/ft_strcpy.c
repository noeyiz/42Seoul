/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:07:33 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:24:05 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strcpy() function copies the string src to dst (including the
 * terminating ‘\0’ character.)  The source and destination strings should
 * not overlap, as the behavior is undefined.
 */
char	*ft_strcpy(char *dst, const char *src)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	while (*src_ptr)
		*dst_ptr++ = *src_ptr++;
	*dst_ptr = '\0';
	return (dst);
}
