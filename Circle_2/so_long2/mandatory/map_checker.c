/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:57:43 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/25 14:29:25 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_rectangle(t_map *map)
{
	if (ft_strlen(map->map_str) != map->col * map->row)
		ft_print_err_and_exit("Error\nMap must be rectangular!");
}

static void	ft_check_components(t_game *game)
{
	int	idx;
	int	player;

	idx = 0;
	player = 0;
	while (game->map.map_str[idx])
	{
		if (game->map.map_str[idx] == 'E')
			game->check_map.exit++;
		else if (game->map.map_str[idx] == 'C')
			game->check_map.collectible++;
		else if (game->map.map_str[idx] == 'P')
		{
			player++;
			game->check_map.pl_idx = idx;
		}
		else if (game->map.map_str[idx] != '1' && game->map.map_str[idx] != '0')
			ft_print_err_and_exit("Error\nUnexpected char(s) in map!");
		idx++;
	}
	if (!game->check_map.exit || !game->check_map.collectible || player != 1)
		ft_print_err_and_exit("Error\nMap must have at least one exit(E)," \
			" one collectible(C), and one starting position(P)!");
	ft_check_valid_path(game);
}

static void	ft_check_wall(t_map *map)
{
	int	cur_col;
	int	cur_row;

	cur_col = 0;
	while (cur_col < map->col)
	{
		if (map->map_str[cur_col] != '1'
			|| map->map_str[(map->row - 1) * map->col + cur_col] != '1')
			ft_print_err_and_exit("Error\nMap must be surrounded by walls!");
		cur_col++;
	}
	cur_row = 0;
	while (cur_row < map->row)
	{
		if (map->map_str[cur_row * map->col] != '1'
			|| map->map_str[cur_row * map->col + (map->col - 1)] != '1')
			ft_print_err_and_exit("Error\nMap must be surrounded by walls!");
		cur_row++;
	}
}

void	ft_verify_map(t_game *game)
{
	game->check_map.exit = 0;
	game->check_map.collectible = 0;
	ft_check_rectangle(&(game->map));
	ft_check_components(game);
	ft_check_wall(&(game->map));
}
