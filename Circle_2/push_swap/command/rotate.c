/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:55:28 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/23 01:55:45 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

static void	ft_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->tail->next;
}

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
