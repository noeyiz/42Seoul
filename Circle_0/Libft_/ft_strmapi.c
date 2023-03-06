/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:03:58 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:34:03 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*map_str;

	size = ft_strlen(s);
	map_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!map_str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map_str[i] = f(i, s[i]);
		i++;
	}
	map_str[i] = '\0';
	return (map_str);
}
