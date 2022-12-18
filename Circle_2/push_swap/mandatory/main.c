/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:25:39 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/18 21:21:05 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_error()
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(1);
}

int	main(int argc, char *argv[])
{
	char	**input;
	
	input = ft_join_split_args(argc, argv);
	if (!input)
		ft_print_error();
	return (0);
}
