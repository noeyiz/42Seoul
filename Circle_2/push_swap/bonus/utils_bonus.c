/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:59:06 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 21:22:19 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_exit(t_exit_type type)
{
	if (type == EXIT_TYPE_ERR)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (type == EXIT_TYPE_KO)
		ft_putstr_fd("KO\n", 1);
	else if (type == EXIT_TYPE_OK)
		ft_putstr_fd("OK\n", 1);
	exit(0);
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
