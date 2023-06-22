/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:20:54 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:20:55 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**make_visited_array(t_map_info map_info)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * (map_info.height + 1));
	if (visited == NULL)
		return (NULL);
	i = -1;
	while (++i < map_info.height)
		visited[i] = ft_strdup(map_info.map[i]);
	visited[i] = NULL;
	return (visited);
}

static void	check_start_point(t_cub *cub, int x, int y)
{
	char	**map;

	map = cub->map_info.map;
	if (is_movable(map[x][y]) == 2)
	{
		if (cub->player.direction != '\0')
			cub->error = 1;
		cub->player.pos.x = x;
		cub->player.pos.y = y;
		cub->player.direction = map[x][y];
	}
}

static void	dfs_visited(int start_x, int start_y, t_cub *cub, char **visited)
{
	t_map_info	map_info;
	int			x;
	int			y;
	int			dir;

	map_info = cub->map_info;
	dir = -1;
	visited[start_x][start_y] = '1';
	while (++dir < 4)
	{
		x = start_x + get_direction(dir);
		y = start_y + get_direction(dir + 1);
		if (x < 0 || y < 0 || x >= map_info.height
			|| y >= map_info.width || visited[x][y] == ' ')
		{
			cub->error = 1;
			return ;
		}
		if (visited[x][y] == '1')
			continue ;
		dfs_visited(x, y, cub, visited);
	}
}

void	check_map(t_cub *cub)
{
	char	**visited;
	int		x;
	int		y;

	visited = make_visited_array(cub->map_info);
	if (visited == NULL)
		cub_error(cub, "Memory allocation failed");
	x = -1;
	while (++x < cub->map_info.height)
	{
		y = -1;
		while (++y < cub->map_info.width && cub->error == 0)
		{
			check_start_point(cub, x, y);
			if (cub->map_info.map[x][y] != '1'
				&& cub->map_info.map[x][y] != ' '
				&& is_movable(cub->map_info.map[x][y]) == 0)
				cub->error = 1;
			if (is_movable(visited[x][y]))
				dfs_visited(x, y, cub, visited);
		}
	}
	free_2d_arr(visited);
	if (cub->player.direction == '\0' || cub->error)
		cub_error(cub, "Not a valid map");
}
