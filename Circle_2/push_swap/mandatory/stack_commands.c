/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:50:10 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 05:32:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_front(t_stack *stack, t_node *new)
{
	if (stack->tail == NULL)
	{
		new->next = new;
		new->prev = new;
		stack->tail = new;
	}
	else
	{
		new->next = stack->tail->next;
		new->prev = stack->tail;
		stack->tail->next->prev = new;
		stack->tail->next = new;
	}
	stack->cur_size += 1;
}

void	ft_push_back(t_stack *stack, t_node *new)
{
	ft_push_front(stack, new);
	stack->tail = new;
}

t_node	*ft_pop_front(t_stack *stack)
{
	t_node	*pop;

	pop = stack->tail->next;
	if (stack->cur_size == 1)
		stack->tail = NULL;
	else
	{
		stack->tail->next = stack->tail->next->next;
		stack->tail->next->prev = stack->tail;
	}
	stack->cur_size -= 1;
	return (pop);
}

t_node	*ft_pop_back(t_stack *stack)
{
	stack->tail = stack->tail->prev;
	return (ft_pop_front(stack));
}
