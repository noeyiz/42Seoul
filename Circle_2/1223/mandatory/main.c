/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:57:01 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/23 03:38:17 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 2)
		ft_error(0);
	ft_parse_args_if(&info, argc, argv);
	if (ft_init_stack(&info) == 0)
	{
		free(info.num_array);
		ft_error(0);
	}
	ft_putstr_fd("=a=\n", 1);
	ft_print_stack(info.a);
	ft_putstr_fd("===\n\n", 1);
	ft_putstr_fd("=b=\n", 1);
	ft_print_stack(info.b);
	ft_putstr_fd("===\n\n", 1);
	// if (ft_check_sorted_stack(a) == FALSE)
	// {
	// 	ft_index_stack(&info);
	// 	ft_sort_stack(&info);
	// }
	return (0);
}
