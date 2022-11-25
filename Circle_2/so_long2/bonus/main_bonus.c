/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:08:58 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/12 15:26:10 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_print_err_and_exit("Invalid number of arguments!");
	ft_init_map(&game.map, argv[1]);
	ft_start_game(&game);
	return (0);
}
