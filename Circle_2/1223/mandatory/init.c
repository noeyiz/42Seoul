/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:26:53 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/23 03:34:40 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_fill_stack_a(t_info *info)
{
	int		idx;
	t_node	*new;

	idx = 0;
	while (idx < info->num_of_args)
	{
		new = ft_create_node(info->num_array[idx]);
		if (new == NULL)
			return (0);
		ft_push_back(info->a, new);
		idx++;
	}
	return (1);
}

int	ft_init_stack(t_info *info)
{
	info->a = ft_create_stack();
	if (info->a == NULL)
		return (0);
	info->b = ft_create_stack();
	if (info->b == NULL)
		return (0);
	if (ft_fill_stack_a(info) == 0)
	{
		ft_free_stack(info->a);
		ft_free_stack(info->b);
		return (0);
	}
	return (1);
}
