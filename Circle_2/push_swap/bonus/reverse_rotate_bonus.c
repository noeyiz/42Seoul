/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:56:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 18:07:53 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->tail->prev;
}

void	ft_rra(t_info *info)
{
	ft_reverse_rotate(info->a);
}

void	ft_rrb(t_info *info)
{
	ft_reverse_rotate(info->b);
}

void	ft_rrr(t_info *info)
{
	ft_reverse_rotate(info->a);
	ft_reverse_rotate(info->b);
}
