/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:14:32 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 15:14:35 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepl(char *s, int c1, int c2)
{
	char	*s_ptr;

	s_ptr = s;
	while (*s_ptr)
	{
		if (*s_ptr == (char)c1)
			*s_ptr = (char)c2;
		s_ptr++;
	}
	return (s);
}
