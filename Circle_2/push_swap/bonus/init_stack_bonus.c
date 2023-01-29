/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:26:53 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 21:24:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

void	ft_init_stack(t_info *info)
{
	info->a = ft_create_stack();
	if (info->a == NULL)
	{
		free(info->num_array);
		ft_exit(EXIT_TYPE_ERR);
	}
	info->b = ft_create_stack();
	if (info->b == NULL)
	{
		ft_free_stack(info->a);
		free(info->num_array);
		ft_exit(EXIT_TYPE_ERR);
	}
	if (ft_fill_stack_a(info) == 0)
	{
		ft_free_stack(info->a);
		ft_free_stack(info->b);
		free(info->num_array);
		ft_exit(EXIT_TYPE_ERR);
	}
}
