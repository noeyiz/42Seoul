/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:44 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/19 18:50:54 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 정수이면 값을 저장하고 1을 리턴, 아니면 0을 리턴 */
int	ft_atoll(char *str, int *ret_n)
{
	long long	result;
	int			sign;
	int			cnt;

	result = 0;
	sign = 1;
	cnt = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		cnt++;
	}
	result *= sign;
	if (*str != '\0' || cnt > 10 || result > 2147483647 || result < -2147483648)
		return (0);
	*ret_n = (int)result;
	return (1);
}

void	ft_free_array(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
