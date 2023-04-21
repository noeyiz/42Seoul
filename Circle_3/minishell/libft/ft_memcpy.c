/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:50:08 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:23:52 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memcpy() function copies n bytes from memory area src to memory area
 * dst.  If dst and src overlap, behavior is undefined.  Applications in which
 * dst and src might overlap should use memmove(3) instead.
 */
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
