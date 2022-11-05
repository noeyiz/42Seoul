/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:07:29 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/26 16:52:45 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sprites.black = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Walls/black.xpm", &width, &height);
	game->sprites.pacfood = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Pacdots/pacdot_food.xpm", &width, &height);
	game->sprites.portal = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Portal/portal.xpm", &width, &height);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Walls/wall.xpm", &width, &height);
}

void	ft_init_pl_sprites(t_game *game)
{
	int	width;
	int	height;

	game->pl_sprites.closed = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_closed.xpm", &width, &height);
	game->pl_sprites.up = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_open_up.xpm", &width, &height);
	game->pl_sprites.up_semi = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_semi_up.xpm", &width, &height);
	game->pl_sprites.down = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_open_down.xpm", &width, &height);
	game->pl_sprites.down_semi = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_semi_down.xpm", &width, &height);
	game->pl_sprites.left = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_open_left.xpm", &width, &height);
	game->pl_sprites.left_semi = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_semi_left.xpm", &width, &height);
	game->pl_sprites.right = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_open_right.xpm", &width, &height);
	game->pl_sprites.right_semi = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Pac-Man/pac_semi_right.xpm", &width, &height);
}

static void	ft_put_image(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, \
	(x + 1) * SIZE, (y + 1) * SIZE);
}

static void	ft_put_player_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.black, \
	(game->player.col + 1) * SIZE, \
	(game->player.row + 1) * SIZE);
	mlx_put_image_to_window(game->mlx, game->win, ft_get_pl_sprite(game), \
	game->player.x + SIZE, game->player.y + SIZE);
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
			col++;
		}
		row++;
	}
	ft_put_player_image(game);
}
