/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:56:09 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/23 01:56:30 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->tail->prev;
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
