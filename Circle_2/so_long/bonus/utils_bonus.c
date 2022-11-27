/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:14:26 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/27 20:15:19 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_err_and_exit(char *message)
{
	ft_putstr_fd("Error\n", 1);
	perror(message);
	exit(1);
}

int	ft_abs(int n, int m)
{
	if (n > m)
		return (n - m);
	else
		return (m - n);
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
