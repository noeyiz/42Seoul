/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:26:35 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/27 20:26:42 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_player(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			if (game->map.map_str[row * game->map.col + col] == 'P')
			{
				game->player.col = col;
				game->player.row = row;
				break ;
			}
			col++;
		}
		row++;
	}
	game->player.x = game->player.col * SIZE;
	game->player.y = game->player.row * SIZE;
	game->player.direction = Stop;
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

void	*ft_get_pl_sprite(t_game *game)
{
	if (game->player.direction == Up)
	{
		if (game->score % 2)
			return (game->pl_sprites.up);
		return (game->pl_sprites.up_semi);
	}
	else if (game->player.direction == Down)
	{
		if (game->score % 2)
			return (game->pl_sprites.down);
		return (game->pl_sprites.down_semi);
	}
	else if (game->player.direction == Left)
	{
		if (game->score % 2)
			return (game->pl_sprites.left);
		return (game->pl_sprites.left_semi);
	}
	else if (game->player.direction == Right)
	{
		if (game->score % 2)
			return (game->pl_sprites.right);
		return (game->pl_sprites.right_semi);
	}
	return (game->pl_sprites.closed);
}

void	ft_put_player_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, ft_get_pl_sprite(game), \
	game->player.x + SIZE, game->player.y + SIZE);
}
