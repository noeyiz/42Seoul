/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:51:26 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/23 02:48:48 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

static void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (from->size == 0)
		return ;
	temp = ft_pop_front(from);
	ft_push_front(to, temp);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
