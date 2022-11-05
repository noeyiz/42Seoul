/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:57:43 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/05 13:57:49 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_rectangle(t_map *map)
{
	if (ft_strlen(map->map_str) != map->col * map->row)
		ft_print_err_and_exit("Map must be rectangular!");
}

static void	ft_check_components(char *map_str)
{
	int	idx;
	int	exit;
	int	collectible;
	int	player;

	idx = 0;
	exit = 0;
	collectible = 0;
	player = 0;
	while (map_str[idx])
	{
		if (map_str[idx] == 'E')
			exit++;
		else if (map_str[idx] == 'C')
			collectible++;
		else if (map_str[idx] == 'P')
			player++;
		else if (map_str[idx] != '1' && map_str[idx] != '0')
			ft_print_err_and_exit("Unexpected char(s) in map!");
		idx++;
	}
	if (!exit || !collectible || player != 1)
		ft_print_err_and_exit("Map must have at least one exit(E)," \
			" one collectible(C), and one starting position(P)!");
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
			ft_print_err_and_exit("Map must be surrounded by walls!");
		cur_col++;
	}
	cur_row = 0;
	while (cur_row < map->row)
	{
		if (map->map_str[cur_row * map->col] != '1'
			|| map->map_str[cur_row * map->col + (map->col - 1)] != '1')
			ft_print_err_and_exit("Map must be surrounded by walls!");
		cur_row++;
	}
}

void	ft_verify_map(t_map *map)
{
	ft_check_rectangle(map);
	ft_check_components(map->map_str);
	ft_check_wall(map);
}
