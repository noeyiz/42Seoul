/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:55:28 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/05 15:17:40 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->tail->next;
}

void	ft_ra(t_info *info)
{
	ft_rotate(info->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_info *info)
{
	ft_rotate(info->b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_info *info)
{
	ft_rotate(info->a);
	ft_rotate(info->b);
	write(1, "rr\n", 3);
}
