/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:56:22 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/19 21:21:25 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_set_index(t_info *info, int *arr)
{
	int		n;
	int		idx;
	int		index;
	t_node	*cur_node;
	t_node	*tmp_node;

	idx = 0;
	cur_node = info->a->tail->next;
	while (idx < info->num_of_args)
	{
		index = 1;
		n = info->num_of_args;
		tmp_node = info->a->tail->next;
		while (n--)
		{
			if (cur_node->data > tmp_node->data)
				index++;
			tmp_node = tmp_node->next;
		}
		arr[idx++] = index;
		cur_node = cur_node->next;
	}
}

static void	ft_index_stack(t_info *info)
{
	int		idx;
	int		*idx_arr;
	t_node	*temp;

	idx_arr = (int *)malloc(sizeof(int) * info->a->size);
	if (idx_arr == NULL)
	{
		ft_free_stack(info->a);
		ft_free_stack(info->b);
		free(info->num_array);
	}
	ft_set_index(info, idx_arr);
	idx = 0;
	temp = info->a->tail->next;
	while (idx < info->num_of_args)
	{
		temp->index = idx_arr[idx++];
		temp = temp->next;
	}
	free(idx_arr);
}

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
		ft_error(ERR_TYPE_ALLOC_FAIL);
	info->b = ft_create_stack();
	if (info->b == NULL)
		ft_error(ERR_TYPE_ALLOC_FAIL);
	if (ft_fill_stack_a(info) == 0)
	{
		ft_free_stack(info->a);
		ft_free_stack(info->b);
		free(info->num_array);
		ft_error(ERR_TYPE_ALLOC_FAIL);
	}
	ft_index_stack(info);
}
