/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:35:14 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/09 21:54:58 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_set_nxt_idx(t_game *game, int *nxt)
{
	int	cur;

	cur = game->map.col * game->enemy.row + game->enemy.col;
	if (game->enemy.direction == Up)
		*nxt = cur - game->map.col;
	else if (game->enemy.direction == Left)
		*nxt = cur - 1;
	else if (game->enemy.direction == Down)
		*nxt = cur + game->map.col;
	else if (game->enemy.direction == Right)
		*nxt = cur + 1;
}

// 다음 칸 갈 수 있으면 가  ... 못가면 방향 바꿔  ... 갔는데 플레이어 만나면 게임 종료 ...
void	ft_move_enemy(t_game *game)
{
	t_direction	dirs[4] = {Up, Left, Down, Right};
	int	nxt;

	ft_set_nxt_idx(game, &nxt);
	if (game->map.map_str[nxt] == '0' || game->map.map_str[nxt] == 'C')
	{
		game->enemy.col = nxt % game->map.col;
		game->enemy.row = nxt / game->map.col;
		printf("col : %d, row : %d\n", game->enemy.col, game->enemy.row);
	}
	else if (game->map.map_str[nxt] == '1' || game->map.map_str[nxt] == 'E')
	{
		game->enemy.direction = dirs[rand() % 4];
		printf("%u\n", game->enemy.direction);
		ft_move_enemy(game);
	}
	else if (game->map.map_str[nxt] == 'P')
	{
		printf("die ~~~~~\n");
		ft_exit_game(game);
	}
}
