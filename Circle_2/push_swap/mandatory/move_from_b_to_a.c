/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:27:03 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/19 20:57:19 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_get_min_move_cnt(t_info *info, int *move_a, int *move_b)
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
			location_b = (info->b->size - cnt) * -1;
		else
			location_b = cnt;
		if (ft_abs(*move_a) + ft_abs(*move_b) > \
		ft_abs(location_a) + ft_abs(location_b))
		{
			*move_a = location_a;
			*move_b = location_b;
		}
		cnt++;
		tmp = tmp->next;
	}
}

static void	ft_rotate_both(t_info *info, int *move_a, int *move_b)
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

void	ft_move_from_b_to_a(t_info *info)
{
	int	move_a;
	int	move_b;

	while (info->b->size)
	{
		move_a = info->a->size;
		move_b = info->b->size;
		ft_get_min_move_cnt(info, &move_a, &move_b);
		ft_rotate_both(info, &move_a, &move_b);
		ft_rotate_a(info, move_a);
		ft_rotate_b(info, move_b);
		ft_pa(info);
	}
}
