/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:52:04 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/25 18:22:29 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_print_err_and_exit("Invalid number of arguments!");
	ft_init_map(&game, argv[1]);
	ft_start_game(&game);
	return (0);
}
