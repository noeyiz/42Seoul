/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:13:03 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/30 16:14:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_print_err("Invalid number of arguments!");
	ft_init_map(&game, argv[1]);
	ft_start_game(&game);
	exit (0);
}
