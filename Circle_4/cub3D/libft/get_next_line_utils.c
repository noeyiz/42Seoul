/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:15:15 by jikoo             #+#    #+#             */
/*   Updated: 2023/05/31 14:23:54 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_nextline(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*ft_strldup(char *str, int start, int size)
{
	int		idx;
	char	*dup_str;

	dup_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!dup_str)
		return (NULL);
	idx = 0;
	while (str[start + idx] && idx < size)
	{
		dup_str[idx] = str[start + idx];
		idx++;
	}
	dup_str[idx] = '\0';
	return (dup_str);
}
