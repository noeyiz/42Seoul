/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:35:14 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/12 14:46:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_set_nxt_idx(t_game *game, int *nxt)
{
	if (game->enemy.direction == Up)
		*nxt = game->map.col * ((game->enemy.y - 8) / 32) \
		+ (game->enemy.x / 32);
	else if (game->enemy.direction == Left)
		*nxt = game->map.col * (game->enemy.y / 32) \
		+ ((game->enemy.x - 8) / 32);
	else if (game->enemy.direction == Down)
		*nxt = game->map.col * ((game->enemy.y + 32) / 32) \
		+ (game->enemy.x / 32);
	else if (game->enemy.direction == Right)
		*nxt = game->map.col * (game->enemy.y / 32) \
		+ ((game->enemy.x + 32) / 32);
}

static void	ft_set_rand_direction(t_game *game)
{
	int	cur;

	cur = game->map.col * (game->enemy.y / 32) + (game->enemy.x / 32);
	if ((game->enemy.direction == Up || game->enemy.direction == Down) \
	&& !(game->enemy.y % 32) \
	&& (game->map.map_str[cur - 1] != '1' || game->map.map_str[cur + 1] != '1'))
	{
		if (rand() % 2)
			game->enemy.direction = Left;
		else
			game->enemy.direction = Right;
	}
	else if ((game->enemy.direction == Left || game->enemy.direction == Right) \
	&& !(game->enemy.x % 32) \
	&& (game->map.map_str[cur - game->map.col] != '1' \
	|| game->map.map_str[cur + game->map.col] != '1'))
	{
		if (rand() % 2)
			game->enemy.direction = Up;
		else
			game->enemy.direction = Down;
	}
}

static void	ft_update_en_info(t_game *game)
{
	if (game->enemy.direction == Up)
		game->enemy.y -= 8;
	else if (game->enemy.direction == Left)
		game->enemy.x -= 8;
	else if (game->enemy.direction == Down)
		game->enemy.y += 8;
	else if (game->enemy.direction == Right)
		game->enemy.x += 8;
}

static int	ft_did_touch(t_game *game)
{
	if (ft_abs(game->player.x, game->enemy.x) < 32 \
	&& ft_abs(game->player.y, game->enemy.y) < 32)
		return (1);
	return (0);
}

void	ft_move_enemy(t_game *game)
{
	int	nxt;

	ft_set_rand_direction(game);
	ft_set_nxt_idx(game, &nxt);
	if (game->map.map_str[nxt] == '0' || game->map.map_str[nxt] == 'C')
		ft_update_en_info(game);
	else if (game->map.map_str[nxt] == '1' || game->map.map_str[nxt] == 'E')
		ft_move_enemy(game);
	else if (ft_did_touch(game))
		ft_exit_game(game);
}
