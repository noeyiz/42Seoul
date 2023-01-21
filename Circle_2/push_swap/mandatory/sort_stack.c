/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:31:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/21 19:40:44 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_case_three_args(t_info *info)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = info->a->tail->next->data;
	val2 = info->a->tail->prev->data;
	val3 = info->a->tail->data;
	if (val1 < val2 && val2 > val3 && val3 > val1)
	{
		ft_sa(info);
		ft_ra(info);
	}
	else if (val1 > val2 && val2 < val3 && val3 > val1)
		ft_sa(info);
	else if (val1 < val2 && val2 > val3 && val3 < val1)
		ft_rra(info);
	else if (val1 > val2 && val2 < val3 && val3 < val1)
		ft_ra(info);
	else if (val1 > val2 && val2 > val3 && val3 < val1)
	{
		ft_sa(info);
		ft_rra(info);
	}
}

static void	ft_div_by_pivot(t_info *info)
{
	int		cnt;
	int		pivot1;
	int		pivot2;
	int		temp;

	cnt = 0;
	pivot1 = info->num_of_args / 3;
	pivot2 = pivot1 * 2;
	while (cnt < info->num_of_args)
	{
		temp = info->a->tail->next->index;
		if (pivot1 < temp && temp <= pivot2)
			ft_pb(info);
		else if (temp <= pivot1)
		{
			ft_pb(info);
			ft_rb(info);
		}
		else
			ft_ra(info);
		cnt++;
	}
	while (info->a->size > 3)
		ft_pb(info);
	ft_case_three_args(info);
}

static void	ft_clean_up(t_info *info)
{
	int	move_cnt;

	move_cnt = ft_find_location(info->a, 1);
	if (move_cnt > info->a->size / 2)
	{
		while (info->a->tail->next->index != 1)
			ft_rra(info);
	}
	else
	{
		while (info->a->tail->next->index != 1)
			ft_ra(info);
	}
}

void	ft_sort_stack(t_info *info)
{
	if (info->num_of_args == 2)
		ft_sa(info);
	else if (info->num_of_args == 3)
		ft_case_three_args(info);
	else
	{
		ft_div_by_pivot(info);
		ft_move_from_b_to_a(info);
		ft_clean_up(info);
	}
}
