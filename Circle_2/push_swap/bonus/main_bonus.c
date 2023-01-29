/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:57:01 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 18:07:45 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc >= 2)
	{	
		ft_parse_args(&info, argc, argv);
		ft_init_stack(&info);
		ft_run_checker(&info);
	}
	return (0);
}
