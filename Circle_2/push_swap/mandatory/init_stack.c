/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:25 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/19 21:46:37 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_create_stack(int size)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->cur_size = 0;
	new->max_size = size;
	new->top = NULL;
	return (new);
}

void	ft_init_stack(t_stack *a, t_stack *b, char **args)
{
	size_t	num_of_args;

	num_of_args = 0;
	while (args[num_of_args])
		num_of_args++;
	*a = ft_create_stack(num_of_args);
	if (*a == NULL)
		ft_print_error(-1);
	*b = ft_create_stack(num_of_args);
	if (*b == NULL)
		ft_print_error(-1);
}
