/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:35:14 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/10 01:28:25 by jikoo            ###   ########.fr       */
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
	t_direction	h_dirs[2] = {Up, Down};
	t_direction	v_dirs[2] = {Left, Right};
	
	if ((game->enemy.direction == Up || game->enemy.direction == Down) && !(game->enemy.y % 32))
		game->enemy.direction = v_dirs[rand() % 2];
	else if ((game->enemy.direction == Left || game->enemy.direction == Right) && !(game->enemy.x % 32))
		game->enemy.direction = h_dirs[rand() % 2];
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

void	ft_move_enemy(t_game *game)
{
	int	nxt;

	ft_set_rand_direction(game);
	ft_set_nxt_idx(game, &nxt);
	if (game->map.map_str[nxt] == '0' || game->map.map_str[nxt] == 'C')
		ft_update_en_info(game);
	else if (game->map.map_str[nxt] == '1' || game->map.map_str[nxt] == 'E')
		ft_move_enemy(game);
	else if (game->map.map_str[nxt] == 'P') // 이 부분 수정 필요
		ft_exit_game(game);
}
