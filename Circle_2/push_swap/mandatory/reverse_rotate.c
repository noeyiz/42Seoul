/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:56:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/05 15:18:50 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->tail->prev;
}

void	ft_rra(t_info *info)
{
	ft_reverse_rotate(info->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_info *info)
{
	ft_reverse_rotate(info->b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_info *info)
{
	ft_reverse_rotate(info->a);
	ft_reverse_rotate(info->b);
	write(1, "rrr\n", 4);
}
