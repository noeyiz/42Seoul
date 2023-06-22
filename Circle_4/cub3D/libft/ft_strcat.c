/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:21:33 by jikoo             #+#    #+#             */
/*   Updated: 2023/05/30 16:14:54 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
