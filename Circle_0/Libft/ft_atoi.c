/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:49:13 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:23:33 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_atoi() function converts the initial portion of the string pointed to
 * by str to int representation.
 */
int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	
	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (num - '0');
		str++;
	}
	return (sign * num);
}