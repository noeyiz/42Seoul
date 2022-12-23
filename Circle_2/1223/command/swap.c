/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:50:45 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/23 01:55:13 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

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

void	ft_sa(t_stack *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
