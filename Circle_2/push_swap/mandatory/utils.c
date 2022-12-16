/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:34:43 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/16 20:30:20 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(1);
}

static int	ft_include_space(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == ' ')
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_join_with_space(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join_str;

	if (!s1 || !s2 || ft_include_space(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!join_str)
		return (NULL);
	idx = 0;
	while (*s1)
		join_str[idx++] = *s1++;
	join_str[idx++] = ' ';
	while (*s2)
		join_str[idx++] = *s2++;
	join_str[idx] = '\0';
	return (join_str);
}
