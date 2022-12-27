/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:59:06 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/27 16:49:00 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 🚨 이건 지워서 내야 한단다 !~ */
#include <stdio.h>
void	ft_print_stack(t_stack *stack)
{
	int		n;
	t_node	*temp;

	n = stack->size;
	if (n == 0)
		return ;
	temp = stack->tail->next;
	while (n--)
	{
		printf("data: %d, index: %d\n", temp->data, temp->index);
		temp = temp->next;
	}
}

/* 서브젝트에 명시된 오류(정수가 아님, 값 중복)는 type 1, 그 외의 오류는 type 0 */
int	ft_error(int type)
{
	if (type == 1)
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

int	ft_check_sorted_stack(t_stack *stack) {
	int		n;
	t_node	*temp;

	n = stack->size - 1;
	temp = stack->tail->next;
	while (n--) {
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
