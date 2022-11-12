/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:48:52 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/12 16:42:53 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_enemy(t_game *game)
{
	int	rand_num;

	game->enemy.direction = Right;
	while (1)
	{
		rand_num = rand() % (ft_strlen(game->map.map_str) - 1);
		if (game->map.map_str[rand_num] == '0' \
		|| game->map.map_str[rand_num] == 'C')
		{
			game->enemy.x = (rand_num % game->map.col) * SIZE;
			game->enemy.y = (rand_num / game->map.col) * SIZE;
			break ;
		}
	}
}

void	ft_init_en_sprites(t_game *game)
{
	int	width;
	int	height;

	game->en_sprites.up1 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_up1.xpm", &width, &height);
	game->en_sprites.up2 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_up2.xpm", &width, &height);
	game->en_sprites.down1 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_down1.xpm", &width, &height);
	game->en_sprites.down2 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_down2.xpm", &width, &height);
	game->en_sprites.left1 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_left1.xpm", &width, &height);
	game->en_sprites.left2 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_left2.xpm", &width, &height);
	game->en_sprites.right1 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_right1.xpm", &width, &height);
	game->en_sprites.right2 = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Ghosts/K/ghost_right2.xpm", &width, &height);
}

void	*ft_get_en_sprite(t_game *game)
{
	if (game->enemy.direction == Up)
	{
		if (game->score % 2)
			return (game->en_sprites.up1);
		return (game->en_sprites.up2);
	}
	else if (game->enemy.direction == Down)
	{
		if (game->score % 2)
			return (game->en_sprites.down1);
		return (game->en_sprites.down2);
	}
	else if (game->enemy.direction == Left)
	{
		if (game->score % 2)
			return (game->en_sprites.left1);
		return (game->en_sprites.left2);
	}
	else if (game->enemy.direction == Right)
	{
		if (game->score % 2)
			return (game->en_sprites.right1);
		return (game->en_sprites.right2);
	}
	return (0);
}

void	ft_put_enemy_image(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, ft_get_en_sprite(game), \
	game->enemy.x + SIZE, game->enemy.y + SIZE);
}
