/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:51:26 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/05 15:18:16 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (from->size == 0)
		return ;
	temp = ft_pop_front(from);
	ft_push_front(to, temp);
}

void	ft_pa(t_info *info)
{
	ft_push(info->b, info->a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_info *info)
{
	ft_push(info->a, info->b);
	write(1, "pb\n", 3);
}
