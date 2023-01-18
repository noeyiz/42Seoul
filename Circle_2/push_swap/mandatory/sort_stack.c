/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:31:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/18 21:45:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_case_two_args(t_info *info)
{
	if (info->a->tail->data < info->a->tail->next->data)
		ft_sa(info);
}

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
		if (temp > pivot1 && temp <= pivot2)
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

static int	ft_get_min_index(t_stack *stack)
{
	int		cnt;
	int		min_idx;
	t_node	*tmp;

	cnt = 0;
	min_idx = 2147483647;
	tmp = stack->tail->next;
	while (cnt < stack->size)
	{
		if (tmp->index < min_idx)
			min_idx = tmp->index;
		cnt++;
		tmp = tmp->next;
	}
	return (min_idx);
}

static int	ft_get_location(t_stack *stack, int min)
{
	int		location;
	t_node	*tmp;

	location = 0;
	tmp = stack->tail->next;
	while (location < stack->size)
	{
		if (tmp->index == min)
			break;
		location++;
		tmp = tmp->next;
	}
	if (location > stack->size / 2)
		location = location - stack->size;
	return (location);
}

static int	ft_find_location_a(t_info *info, int index)
{
	int		cnt;
	int		location;
	t_node	*tmp;

	cnt = 0;
	location = 0;
	tmp = info->a->tail->next;
	if (index < ft_get_min_index(info->a))
	{
		return (ft_get_location(info->a, ft_get_min_index(info->a)));
	}
	while (cnt < info->a->size)
	{
		if (tmp->index < index)
			location = cnt + 1;
		cnt++;
		tmp = tmp->next;
	}
	if (location > info->a->size / 2)
		location =  location - info->a->size - 1;
	return (location);
}

static int ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	ft_get_min_rotate(t_info *info, int *move_a, int *move_b)
{
	int		cnt;
	int		index;
	int		location_a;
	int		location_b;
	t_node	*tmp;

	cnt = 0;
	tmp = info->b->tail->next;
	while (cnt < info->b->size)
	{
		index = tmp->index;
		location_a = ft_find_location_a(info, index);
		if (cnt > info->b->size / 2)
			location_b = cnt - info->b->size;
		else
			location_b = cnt;
		if (ft_abs(*move_a) + ft_abs(*move_b) > ft_abs(location_a) + ft_abs(location_b))
		{
			*move_a = location_a;
			*move_b = location_b;
		}
		cnt++;
		tmp = tmp->next;
	}
}

static void	ft_rotate_same(t_info *info, int *move_a, int *move_b)
{
	while (*move_a > 0 && *move_b > 0)
	{
		ft_rr(info);
		*move_a -= 1;
		*move_b -= 1;
	}
	while (*move_a < 0 && *move_b < 0)
	{
		ft_rrr(info);
		*move_a += 1;
		*move_b += 1;
	}
}

static void	ft_rotate_a(t_info *info, int move_cnt)
{
	while (move_cnt)
	{
		if (move_cnt > 0)
		{
			ft_ra(info);
			move_cnt--;
		}
		else
		{
			ft_rra(info);
			move_cnt++;
		}
	}
}

static void	ft_rotate_b(t_info *info, int move_cnt)
{
	while (move_cnt)
	{
		if (move_cnt > 0)
		{
			ft_rb(info);
			move_cnt--;
		}
		else
		{
			ft_rrb(info);
			move_cnt++;
		}
	}
}

static void	ft_move_from_b_to_a(t_info *info)
{
	int	move_a;
	int	move_b;
	while (info->b->size)
	{
		move_a = info->a->size;
		move_b = info->b->size;
		ft_get_min_rotate(info, &move_a, &move_b);
		ft_rotate_same(info, &move_a, &move_b);
		ft_rotate_a(info, move_a);
		ft_rotate_b(info, move_b);
		ft_pa(info);
	}
}

void	ft_sort_stack(t_info *info)
{
	if (info->num_of_args == 2)
		ft_case_two_args(info);
	else if (info->num_of_args == 3)
		ft_case_three_args(info);
	else
	{
		ft_div_by_pivot(info);
		ft_move_from_b_to_a(info);
	}
}