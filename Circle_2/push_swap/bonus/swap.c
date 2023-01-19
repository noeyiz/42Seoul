/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:50:45 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/19 16:26:57 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_swap(t_stack *stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if (stack->size < 2)
		return ;
	temp1 = ft_pop_front(stack);
	temp2 = ft_pop_front(stack);
	ft_push_front(stack, temp1);
	ft_push_front(stack, temp2);
}

void	ft_sa(t_info *info)
{
	ft_swap(info->a);
}

void	ft_sb(t_info *info)
{
	ft_swap(info->b);
}

void	ft_ss(t_info *info)
{
	ft_swap(info->a);
	ft_swap(info->b);
}
