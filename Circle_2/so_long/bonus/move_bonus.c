/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:27:24 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/27 20:27:30 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_set_nxt_idx(t_game *game, int *nxt, t_direction dir)
{
	if (dir == Up)
		*nxt = game->map.col * ((game->player.y - 8) / 32) \
		+ (game->player.x / 32);
	else if (dir == Left)
		*nxt = game->map.col * (game->player.y / 32) \
		+ ((game->player.x - 8) / 32);
	else if (dir == Down)
		*nxt = game->map.col * ((game->player.y + 32) / 32) \
		+ (game->player.x / 32);
	else if (dir == Right)
		*nxt = game->map.col * (game->player.y / 32) \
		+ ((game->player.x + 32) / 32);
}

static void	ft_set_nxt2_idx(t_game *game, int nxt, int *nxt2, t_direction dir)
{
	if (dir == Up && game->player.x % 32)
		*nxt2 = game->map.col * ((game->player.y - 8) / 32) \
		+ ((game->player.x + 32) / 32);
	else if (dir == Left && game->player.y % 32)
		*nxt2 = game->map.col * ((game->player.y + 32) / 32) \
		+ ((game->player.x - 8) / 32);
	else if (dir == Down && game->player.x % 32)
		*nxt2 = game->map.col * ((game->player.y + 32) / 32) \
		+ ((game->player.x + 32) / 32);
	else if (dir == Right && game->player.y % 32)
		*nxt2 = game->map.col * ((game->player.y + 32) / 32) \
		+ ((game->player.x + 32) / 32);
	else
		*nxt2 = nxt;
}

static void	ft_update_pl_info(t_game *game, t_direction direction)
{
	game->score++;
	game->player.direction = direction;
	if (direction == Up)
		game->player.y -= 8;
	else if (direction == Left)
		game->player.x -= 8;
	else if (direction == Down)
		game->player.y += 8;
	else if (direction == Right)
		game->player.x += 8;
}

static int	ft_check_and_update_pl_coord(t_game *game, t_direction direction)
{
	if ((direction == Up || direction == Down) \
	&& !(game->player.y % 32))
	{
		game->player.row = game->player.y / 32;
		return (1);
	}
	else if ((direction == Left || direction == Right) \
	&& !(game->player.x % 32))
	{
		game->player.col = game->player.x / 32;
		return (1);
	}
	return (0);
}

void	ft_move(t_game *game, t_direction direction)
{
	int	cur;
	int	nxt;
	int	nxt2;

	cur = game->map.col * game->player.row + game->player.col;
	ft_set_nxt_idx(game, &nxt, direction);
	ft_set_nxt2_idx(game, nxt, &nxt2, direction);
	if ((game->map.map_str[nxt] == 'E' || game->map.map_str[nxt2] == 'E') \
	&& game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1' && game->map.map_str[nxt2] != '1')
	{
		ft_update_pl_info(game, direction);
		if (ft_check_and_update_pl_coord(game, direction))
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		ft_move_enemy(game);
		ft_set_sprites(game);
	}
}
