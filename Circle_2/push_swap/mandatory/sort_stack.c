/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:31:09 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/28 00:16:11 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_case_two_args(t_stack *stack)
{
	if (stack->tail->data < stack->tail->next->data)
		ft_sa(stack);
}

static int	ft_get_case(int a, int b, int c)
{
	if (a < b && b > c && c > a)
		return (1);
	else if (a > b && b < c && c > a)
		return ( 2);
	else if (a < b && b > c && c < a)
		return (3);
	else if (a > b && b < c && c < a)
		return (4);
	else if (a > b && b > c && c < a)
		return (5);
	return (0);
}

static void	ft_case_three_args(t_stack *stack)
{
	int	case_num;

	case_num = ft_get_case(stack->tail->next->data, stack->tail->prev->data, \
	stack->tail->data);
	if (case_num == 1)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (case_num == 2)
		ft_sa(stack);
	else if (case_num == 3)
		ft_rra(stack);
	else if (case_num == 4)
		ft_ra(stack);
	else if (case_num == 5)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}

void	ft_sort_stack(t_info *info)
{
	if (info->num_of_args == 2)
		ft_case_two_args(info->a);
	else if (info->num_of_args == 3)
		ft_case_three_args(info->a);
}