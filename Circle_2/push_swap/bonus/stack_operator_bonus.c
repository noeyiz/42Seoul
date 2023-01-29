/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:11:17 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 18:07:57 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
	stack->size++;
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
	if (stack->size == 1)
		stack->tail = NULL;
	else
	{
		stack->tail->next = stack->tail->next->next;
		stack->tail->next->prev = stack->tail;
	}
	stack->size--;
	return (pop);
}

t_node	*ft_pop_back(t_stack *stack)
{
	stack->tail = stack->tail->prev;
	return (ft_pop_front(stack));
}
