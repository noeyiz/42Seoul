/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:04:55 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:34:03 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] && i + j < len)
	{
		if (haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
