/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:54:23 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 21:29:20 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	ft_atoll_if(char *str)
{
	long long	result;
	int			sign;
	int			count;

	result = 0;
	sign = 1;
	count = 0;
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
		count++;
	}
	result *= sign;
	if (*str != '\0' || count == 0 || count > 11 || \
	result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}

int	ft_check_int(char **args)
{
	int	idx;

	idx = 0;
	while (args[idx])
	{
		if (ft_atoll_if(args[idx]))
			idx++;
		else
			return (0);
	}
	return (1);
}

void	ft_set_num_array(t_info *info, char **args)
{
	int	idx;

	idx = 0;
	info->num_of_args = 0;
	while (args[info->num_of_args])
		info->num_of_args++;
	info->num_array = (int *)malloc(sizeof(int) * info->num_of_args);
	if (info->num_array == NULL)
	{
		ft_free_array(args);
		ft_exit(EXIT_TYPE_ERR);
	}
	while (idx < info->num_of_args)
	{
		info->num_array[idx] = ft_atoi(args[idx]);
		idx++;
	}
}

int	ft_check_dup(t_info *info)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < info->num_of_args)
	{
		idx2 = 0;
		while (idx2 < idx1)
		{
			if (info->num_array[idx1] == info->num_array[idx2])
				return (0);
			idx2++;
		}
		idx1++;
	}
	return (1);
}
