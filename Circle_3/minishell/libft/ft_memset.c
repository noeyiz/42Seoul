/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:42:55 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/28 16:58:02 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memset() function writes len bytes of value c (converted to an
 * unsigned char) to the string b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_ptr;

	b_ptr = (unsigned char *)b;
	while (len--)
		*b_ptr++ = c;
	return (b);
}
