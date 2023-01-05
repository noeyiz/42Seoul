/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:31:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/05 18:02:54 by jikoo            ###   ########.fr       */
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
		temp = info->a->tail->next->data;
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

// static void	ft_get_min_rotate(t_info *info, int *move_a, int *move_b)
// {
// 	// 가장 적은 명령어로 스택 a에 끼워넣을 수 있는 스택 b의 숫자 찾기
// }

// static void	ft_rotate_same(t_info *info, int *move_a, int *move_b)
// {
// 	while (*move_a > 0 && *move_b > 0)
// 	{
// 		ft_rr(info->a, info->b);
// 		*move_a -= 1;
// 		*move_b -= 1;
// 	}
// 	while (*move_a < 0 && *move_b < 0)
// 	{
// 		ft_rrr(info->a, info->b);
// 		*move_a += 1;
// 		*move_b += 1;
// 	}
// }

// static void	ft_rotate_a(t_info *info, int move_cnt)
// {
// 	while (move_cnt)
// 	{
// 		if (move_cnt > 0)
// 		{
// 			ft_ra(info->a);
// 			move_cnt--;
// 		}
// 		else
// 		{
// 			ft_rra(info->a);
// 			move_cnt++;
// 		}
// 	}
// }

// static void	ft_rotate_b(t_info *info, int move_cnt)
// {
// 	while (move_cnt)
// 	{
// 		if (move_cnt > 0)
// 		{
// 			ft_rb(info->b);
// 			move_cnt--;
// 		}
// 		else
// 		{
// 			ft_rrb(info->b);
// 			move_cnt++;
// 		}
// 	}
// }

// static void	ft_move_from_b_to_a(t_info *info)
// {
// 	int	move_a;
// 	int	move_b;
// 	while (info->b->size)
// 	{
// 		move_a = 0;
// 		move_b = 0;
// 		ft_get_min_rotate(info, &move_a, &move_b);
// 		ft_rotate_same(info, &move_a, &move_b);
// 		ft_rotate_a(info, move_a);
// 		ft_rotate_b(info, move_b);
// 		ft_pa(info->a, info->b);
// 	}
// }

void	ft_sort_stack(t_info *info)
{
	if (info->num_of_args == 2)
		ft_case_two_args(info);
	else if (info->num_of_args == 3)
		ft_case_three_args(info);
	else
	{
		ft_div_by_pivot(info);
		// ft_move_from_b_to_a(info);
	}
}