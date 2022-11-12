/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:41:54 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/12 15:26:58 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_print_err_and_exit(char *message)
{
	printf(RED "Error\n" RESET "%s\n", message);
	exit(1);
}

int	ft_abs(int n, int m)
{
	if (n > m)
		return (n - m);
	else
		return (m - n);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strrepl(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
	return (str);
}
