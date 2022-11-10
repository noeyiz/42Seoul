/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:07:29 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/10 16:47:10 by jikoo            ###   ########.fr       */
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

static void	ft_put_image(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, \
	(x + 1) * SIZE, (y + 1) * SIZE);
}

static void	ft_put_player_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, ft_get_pl_sprite(game), \
	game->player.x + SIZE, game->player.y + SIZE);
}

static void	ft_put_enemy_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, ft_get_en_sprite(game), \
	game->enemy.x + SIZE, game->enemy.y + SIZE);
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
			ft_put_image(game, game->sprites.black, col, row);
			idx = row * game->map.col + col;
			if (game->map.map_str[idx] == '1')
				ft_put_image(game, game->sprites.wall, col, row);
			if (game->map.map_str[idx] == 'E')
				ft_put_image(game, game->sprites.portal, col, row);
			if (game->map.map_str[idx] == 'C')
				ft_put_image(game, game->sprites.pacfood, col, row);
			col++;
		}
		row++;
	}
	ft_put_player_image(game);
	ft_put_enemy_image(game);
}
