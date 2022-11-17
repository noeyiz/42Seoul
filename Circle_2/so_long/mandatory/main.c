/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:56:45 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/17 19:33:23 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_err_and_exit(char *message)
{
	printf(RED "Error\n" RESET "%s\n", message);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_print_err_and_exit("Invalid number of arguments!");
	ft_init_map(&game, argv[1]);
	ft_start_game(&game);
	return (0);
}
