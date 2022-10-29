/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:46:50 by jikoo             #+#    #+#             */
/*   Updated: 2022/09/06 19:47:09 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join_str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!join_str)
		return (NULL);
	idx = 0;
	while (*s1)
		join_str[idx++] = *s1++;
	while (*s2)
		join_str[idx++] = *s2++;
	join_str[idx] = '\0';
	return (join_str);
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
