/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:58:07 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/25 14:38:25 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_set_cur_idx(t_map *map, int *cur)
{
	int	idx;

	idx = 0;
	while (map->map_str[idx])
	{
		if (map->map_str[idx] == 'P')
			*cur = idx;
		idx++;
	}
}

static void	ft_set_nxt_idx(t_map *map, t_direction direction, int cur, int *nxt)
{
	if (direction == Up)
		*nxt = cur - map->col;
	else if (direction == Down)
		*nxt = cur + map->col;
	else if (direction == Left)
		*nxt = cur - 1;
	else if (direction == Right)
		*nxt = cur + 1;
}

void	ft_move(t_game *game, t_direction direction)
{
	int	cur;
	int	nxt;

	ft_set_cur_idx(&game->map, &cur);
	ft_set_nxt_idx(&game->map, direction, cur, &nxt);
	if (game->map.map_str[nxt] != '1')
	{
		if (game->map.map_str[nxt] == 'C')
			game->collectible--;
		if (game->map.map_str[nxt] == 'E')
		{
			if (game->collectible)
				return ;
			else
				ft_exit_game(game);
		}
		ft_putstr("count : ");
		ft_putnbr(++game->cnt);
		write(1, "\n", 1);
		game->map.map_str[cur] = '0';
		game->map.map_str[nxt] = 'P';
	}
	ft_set_sprites(game);
}
