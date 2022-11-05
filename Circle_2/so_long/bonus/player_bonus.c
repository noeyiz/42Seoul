/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:06:02 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/26 16:50:56 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_player(t_game *game)
{
	int	col;
	int	row;

	game->player.cnt = 0;
	game->player.direction = Stop;
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
			}
			col++;
		}
		row++;
	}
	game->player.x = game->player.col * SIZE;
	game->player.y = game->player.row * SIZE;
}

void	*ft_get_pl_sprite(t_game *game)
{
	if (game->player.direction == Up)
	{
		if (game->player.cnt % 2)
			return (game->pl_sprites.up);
		return (game->pl_sprites.up_semi);
	}
	else if (game->player.direction == Down)
	{
		if (game->player.cnt % 2)
			return (game->pl_sprites.down);
		return (game->pl_sprites.down_semi);
	}
	else if (game->player.direction == Left)
	{
		if (game->player.cnt % 2)
			return (game->pl_sprites.left);
		return (game->pl_sprites.left_semi);
	}
	else if (game->player.direction == Right)
	{
		if (game->player.cnt % 2)
			return (game->pl_sprites.right);
		return (game->pl_sprites.right_semi);
	}
	return (game->pl_sprites.closed);
}
