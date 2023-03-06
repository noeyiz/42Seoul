/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:28:45 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:24:16 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strlen() function computes the length of the string s.
 */
size_t	ft_strlen(const char *s)
{
	const char	*s_ptr;
	
	s_ptr = s;
	while (*s_ptr != '\0')
		s_ptr++;
	return (s_ptr - s);
}
