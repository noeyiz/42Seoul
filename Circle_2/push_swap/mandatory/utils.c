/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:10:10 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 05:37:48 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_ps_error(int type)
{
	if (type == 1)
		write(1, "Error\n", 6);
	/* 여기부터 */
	if (type == -1)
		write(1, "Allocation Failed!\n", 19);
	if (type == 0)
		write(1, "etc error :3 ...\n", 17);
	/* 여기까지는 지워서 제출하깅 */
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
	while (stack->cur_size)
		free(ft_pop_front(stack));
	free(stack);
}
