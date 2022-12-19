/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:01:22 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 05:43:38 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 정수이면 1을 리턴, 아니면 0을 리턴 */
static int	ft_atoll_if(char *str)
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
	if (*str != '\0' || cnt > 10 || result == 0 || \
	result > 2147483647 || result < -2147483648)
		return (FALSE);
	return (TRUE);
}

static void	ft_check_int(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		if (ft_atoll_if(arr[idx]))
			idx++;
		else
		{
			ft_free_array(arr);
			ft_ps_error(1);
		}
	}
}

static void	ft_check_dup(char **arr)
{
	int	idx_1;
	int	idx_2;
	int	offset_1;
	int	offset_2;

	idx_1 = -1;
	while (arr[++idx_1])
	{
		idx_2 = -1;
		offset_1 = 0;
		if (*arr[idx_1] == '+')
			offset_1 = 1;
		while (++idx_2 < idx_1)
		{
			offset_2 = 0;
			if (*arr[idx_2] == '+')
				offset_2 = 1;
			if (ft_strncmp(arr[idx_1] + offset_1, arr[idx_2] + \
			offset_2, ft_strlen(arr[idx_1] + offset_1)) == 0)
			{
				ft_free_array(arr);
				ft_ps_error(1);
			}
		}
	}
}

void	ft_verify_args(char **args)
{
	ft_check_int(args);
	ft_check_dup(args);
}
