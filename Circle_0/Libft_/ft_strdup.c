/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:28:07 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:34:03 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dup_str;

	len = ft_strlen(s1);
	dup_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup_str[i] = s1[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
