/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:57:01 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/21 16:44:39 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 2)
		ft_exit(EXIT_TYPE_ETC);
	ft_parse_args(&info, argc, argv);
	ft_init_stack(&info);
	if (ft_check_sorted_stack(info.a) == 0)
		ft_run_checker(&info);
	return (0);
}
