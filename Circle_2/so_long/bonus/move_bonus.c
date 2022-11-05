/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:20:11 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/05 21:55:11 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_move_up(t_game *game)
{
	int	cur;
	int	nxt;
	int	nxt2;
	
	cur = game->map.col * game->player.row + game->player.col;
	// cur = game->map.col * (game->player.y / 32) + (game->player.x / 32);
	nxt = game->map.col * ((game->player.y - 8) / 32) + (game->player.x / 32);
	if (game->player.x % 32)
		nxt2 = game->map.col * ((game->player.y - 8) / 32) + ((game->player.x + 32) / 32);
	else
		nxt2 = nxt;
	printf("cur : %c, nxt : %c\n", game->map.map_str[cur], game->map.map_str[nxt]);
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1' && game->map.map_str[nxt2] != '1')
	{
		game->player.y -= 8;
		if (game->player.y % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.row = game->player.y / 32;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Up;
		ft_set_sprites(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	cur;
	int	nxt;
	int	nxt2;

	cur = game->map.col * game->player.row + game->player.col;
	// cur = game->map.col * (game->player.y / 32) + (game->player.x / 32);
	nxt = game->map.col * ((game->player.y + 32) / 32) + (game->player.x / 32);
	if (game->player.x % 32)
		nxt2 = game->map.col * ((game->player.y + 32) / 32) + ((game->player.x + 32) / 32);
	else
		nxt2 = nxt;
	printf("cur : %c, nxt : %c\n", game->map.map_str[cur], game->map.map_str[nxt]);
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1' && game->map.map_str[nxt2] != '1')
	{
		game->player.y += 8;
		if (game->player.y % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.row = game->player.y / 32;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Down;
		ft_set_sprites(game);
	}
}

void	ft_move_left(t_game *game)
{
	int	cur;
	int	nxt;
	int	nxt2;

	cur = game->map.col * game->player.row + game->player.col;
	// cur = game->map.col * (game->player.y / 32) + (game->player.x / 32);
	nxt = game->map.col * (game->player.y / 32) + ((game->player.x - 8) / 32);
	if (game->player.y % 32)
		nxt2 = game->map.col * ((game->player.y + 32) / 32) + ((game->player.x - 8) / 32);
	else
		nxt2 = nxt;
	printf("cur : %c, nxt : %c\n", game->map.map_str[cur], game->map.map_str[nxt]);
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1' && game->map.map_str[nxt2] != '1')
	{
		game->player.x -= 8;
		if (game->player.x % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.col = game->player.x / 32;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Left;
		ft_set_sprites(game);
	}
}

void	ft_move_right(t_game *game)
{
	int	cur;
	int	nxt;
	int	nxt2;

	cur = game->map.col * game->player.row + game->player.col;
	// cur = game->map.col * (game->player.y / 32) + (game->player.x / 32);
	nxt = game->map.col * (game->player.y / 32) + ((game->player.x + 32) / 32);
	if (game->player.y % 32)
		nxt2 = game->map.col * ((game->player.y + 32) / 32) + ((game->player.x + 32) / 32);
	else
		nxt2 = nxt;
	printf("cur : %c, nxt : %c\n", game->map.map_str[cur], game->map.map_str[nxt]);
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1' && game->map.map_str[nxt2] != '1')
	{
		game->player.x += 8;
		if (game->player.x % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.col = game->player.x / 32;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Right;
		ft_set_sprites(game);
	}
}
