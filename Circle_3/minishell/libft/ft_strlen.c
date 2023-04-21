/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:28:45 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/31 13:57:02 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strlen() function computes the length of the string s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}
