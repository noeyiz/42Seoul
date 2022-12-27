/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:57:01 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/27 22:16:20 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 2)
		ft_error(0);
	ft_parse_args(&info, argc, argv);
	ft_init_stack(&info);
	if (ft_check_sorted_stack(info.a) == 0)
	{
		ft_index_stack(&info);
		ft_sort_stack(&info);
	}
	ft_print_stack(info.a);
	return (0);
}
