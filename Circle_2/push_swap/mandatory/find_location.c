/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_location.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:52:53 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/21 18:17:46 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_min_index(t_stack *stack)
{
	int		cnt;
	int		min_idx;
	t_node	*tmp;

	cnt = 0;
	min_idx = 2147483647;
	tmp = stack->tail->next;
	while (cnt < stack->size)
	{
		if (tmp->index < min_idx)
			min_idx = tmp->index;
		cnt++;
		tmp = tmp->next;
	}
	return (min_idx);
}

static int	ft_get_min_location(t_stack *stack)
{
	int		target;
	int		location;
	t_node	*tmp;

	target = ft_get_min_index(stack);
	location = 0;
	tmp = stack->tail->next;
	while (location < stack->size)
	{
		if (tmp->index == target)
			break ;
		location++;
		tmp = tmp->next;
	}
	if (location > stack->size / 2)
		location = (stack->size - location) * -1;
	return (location);
}

static int	ft_get_max_index(t_stack *stack)
{
	int		cnt;
	int		max_idx;
	t_node	*tmp;

	cnt = 0;
	max_idx = 0;
	tmp = stack->tail->next;
	while (cnt < stack->size)
	{
		if (tmp->index > max_idx)
			max_idx = tmp->index;
		cnt++;
		tmp = tmp->next;
	}
	return (max_idx);
}

static int	ft_get_max_location(t_stack *stack)
{
	int		target;
	int		location;
	t_node	*tmp;

	target = ft_get_max_index(stack);
	location = 0;
	tmp = stack->tail->next;
	while (location < stack->size)
	{
		if (tmp->index == target)
			break ;
		location++;
		tmp = tmp->next;
	}
	if (location > stack->size / 2)
		location = (stack->size - location) * -1;
	return (location);
}

int	ft_find_location(t_stack *stack, int index)
{
	int		cnt;
	int		location;
	t_node	*tmp;

	cnt = 0;
	location = 0;
	tmp = stack->tail->next;
	if (index < ft_get_min_index(stack))
		return (ft_get_min_location(stack));
	else if (index > ft_get_max_index(stack))
		return (ft_get_max_location(stack) + 1);
	while (cnt < stack->size - 1)
	{
		if (tmp->index < index && index < tmp->next->index)
			location = cnt + 1;
		cnt++;
		tmp = tmp->next;
	}
	if (location > stack->size / 2)
		location = (stack->size - location) * -1;
	return (location);
}
