/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:55:28 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 18:07:55 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	ft_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->tail->next;
}

void	ft_ra(t_info *info)
{
	ft_rotate(info->a);
}

void	ft_rb(t_info *info)
{
	ft_rotate(info->b);
}

void	ft_rr(t_info *info)
{
	ft_rotate(info->a);
	ft_rotate(info->b);
}
