/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:21:19 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:21:20 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	push_space(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] && str[idx] == ' ')
		idx++;
	return (idx);
}

static void	set_img_path(t_cub *cub, char **path_ptr,
	char *line, t_element flag)
{
	char	**split;

	if (cub->map_info.check[flag] == 1)
		cub_error(cub, "Some elements are duplicated");
	cub->map_info.check[flag] = 1;
	split = ft_split(line, ' ');
	if (split == NULL || split[1] == NULL || split[2])
	{
		free_2d_arr(split);
		cub_error(cub, "Wrong texture path");
	}
	*path_ptr = ft_strdup(split[1]);
	free_2d_arr(split);
}

static void	set_color(t_cub *cub, unsigned int *color,
	char *line, t_element flag)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	if (cub->map_info.check[flag] == 1)
		cub_error(cub, "Some elements are duplicated");
	cub->map_info.check[flag] = 1;
	split = ft_split(line + 1, ',');
	if (split == NULL || split[1] == NULL || split[2] == NULL || split[3])
	{
		free_2d_arr(split);
		cub_error(cub, "Memory allocation failed");
	}
	r = cub_atoi(split[0]);
	g = cub_atoi(split[1]);
	b = cub_atoi(split[2]);
	free_2d_arr(split);
	if (r == -1 || g == -1 || b == -1)
		cub_error(cub, "Wrong color value");
	*color = r << 16 | g << 8 | b;
}

static int	is_map_element_set(t_cub *cub)
{
	int	idx;

	idx = -1;
	while (++idx < 6)
		if (cub->map_info.check[idx] == 0)
			return (0);
	return (1);
}

void	parse_map_element(t_cub *cub)
{
	char	*line;
	int		idx;

	while (is_map_element_set(cub) == 0)
	{
		line = ft_strrepl(get_next_line(cub->fd), '\n', '\0');
		if (line == NULL)
			cub_error(cub, "Lack of some elements");
		idx = push_space(line);
		if (ft_strncmp(line + idx, "NO ", 3) == 0)
			set_img_path(cub, &cub->map_info.north_path, line, NORTH);
		else if (ft_strncmp(line + idx, "SO ", 3) == 0)
			set_img_path(cub, &cub->map_info.south_path, line, SOUTH);
		else if (ft_strncmp(line + idx, "WE ", 3) == 0)
			set_img_path(cub, &cub->map_info.west_path, line, WEST);
		else if (ft_strncmp(line + idx, "EA ", 3) == 0)
			set_img_path(cub, &cub->map_info.east_path, line, EAST);
		else if (ft_strncmp(line + idx, "F ", 2) == 0)
			set_color(cub, &cub->map_info.color_floor, line, FLOOR);
		else if (ft_strncmp(line + idx, "C ", 2) == 0)
			set_color(cub, &cub->map_info.color_ceiling, line, CEILING);
		else if (is_empty_line(line + idx) == 0)
			cub_error(cub, "Contain wrong elements");
		free(line);
	}
}
