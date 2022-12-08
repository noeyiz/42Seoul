/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:24:22 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/08 16:05:45 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sprites.black = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Other/Walls/black.xpm", &width, &height);
	game->sprites.pacfood = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Other/Pacdots/pacdot_food.xpm", &width, &height);
	game->sprites.pacman = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Pac-Man/pac_closed.xpm", &width, &height);
	game->sprites.portal = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Other/Portal/portal.xpm", &width, &height);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Other/Walls/wall.xpm", &width, &height);
}

void	ft_destroy_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->sprites.black);
	mlx_destroy_image(game->mlx_ptr, game->sprites.pacfood);
	mlx_destroy_image(game->mlx_ptr, game->sprites.pacman);
	mlx_destroy_image(game->mlx_ptr, game->sprites.portal);
	mlx_destroy_image(game->mlx_ptr, game->sprites.wall);
}

static void	ft_put_image(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite, \
		(x + 1) * SIZE, (y + 1) * SIZE);
}

void	ft_set_sprites(t_game *game)
{
	int	col;
	int	row;
	int	idx;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			idx = row * game->map.col + col;
			if (game->map.map_str[idx] == '1')
				ft_put_image(game, game->sprites.wall, col, row);
			if (game->map.map_str[idx] == '0')
				ft_put_image(game, game->sprites.black, col, row);
			if (game->map.map_str[idx] == 'E')
				ft_put_image(game, game->sprites.portal, col, row);
			if (game->map.map_str[idx] == 'C')
				ft_put_image(game, game->sprites.pacfood, col, row);
			if (game->map.map_str[idx] == 'P')
				ft_put_image(game, game->sprites.pacman, col, row);
			col++;
		}
		row++;
	}
}
