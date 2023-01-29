/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:59:06 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 17:07:11 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_exit()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
	return (-1);
}

void	ft_free_array(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}

void	ft_free_stack(t_stack *stack)
{
	while (stack->size)
		free(ft_pop_front(stack));
	free(stack);
}

int	ft_check_sorted_stack(t_stack *stack)
{
	int		n;
	t_node	*temp;

	n = stack->size - 1;
	temp = stack->tail->next;
	while (n--)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
