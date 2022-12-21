/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:36:05 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 09:49:23 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_create_stack(int size)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->cur_size = 0;
	new->max_size = size;
	new->tail = NULL;
	return (new);
}

static t_node	*ft_create_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/* atoi한 값을 스택의 bottom부터 넣어줌 */
static int	ft_fill_stack_a(t_stack **a, char **args)
{
	int		idx;
	t_node	*new;

	idx = 0;
	while (args[idx])
	{
		new = ft_create_node(ft_atoi(args[idx]));
		if (new == NULL)
			return (FALSE);
		ft_push_back(*a, new);
		idx++;
	}
	ft_free_array(args);
	return (TRUE);
}

void	ft_init_stack(t_stack **a, t_stack **b, char **args)
{
	int	num_of_args;

	num_of_args = 0;
	while (args[num_of_args])
		num_of_args++;
	*a = ft_create_stack(num_of_args);
	if (*a == NULL)
		ft_ps_error(-1);
	*b = ft_create_stack(num_of_args);
	if (*b == NULL)
		ft_ps_error(-1);
	if (ft_fill_stack_a(a, args) == FALSE)
	{
		ft_free_stack(*a);
		ft_free_stack(*b);
		ft_free_array(args);
		ft_ps_error(-1);
	}
}

int	ft_check_sorted_stack(t_stack *stack)
{
	int		n;
	t_node	*temp;

	n = stack->max_size;
	temp = stack->tail;
	while (--n)
	{
		if (temp->data <= temp->prev->data)
			return (FALSE);
		temp = temp->prev;
	}
	return (TRUE);
}
