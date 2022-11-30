/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:38:09 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/30 16:14:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_file_type(char *file_name)
{
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4))
		ft_print_err("Invalid file type, use .ber!");
}

static void	ft_count_col_and_row(t_map *map, char *file_name)
{
	int		fd;
	int		cur_col;
	char	buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_err("File not found!");
	cur_col = 0;
	map->col = 0;
	map->row = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			if (map->col < cur_col)
				map->col = cur_col;
			cur_col = 0;
			map->row++;
		}
		else
			cur_col++;
	}
	close(fd);
}

static void	ft_set_map(t_map *map, char *file_name, int idx)
{
	int		fd;
	int		cur_col;
	int		cur_row;
	char	*line;

	map->map_str = (char *)malloc(sizeof(char) * (map->col * map->row + 1));
	if (!map->map_str)
		ft_print_err("Memory allocation error!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_err("File not found!");
	cur_row = 0;
	while (cur_row < map->row)
	{
		line = ft_strrepl(get_next_line(fd), '\n', '\0');
		cur_col = 0;
		while ((size_t)cur_col < ft_strlen(line))
		{
			map->map_str[idx++] = line[cur_col];
			cur_col++;
		}
		cur_row++;
	}
	close(fd);
	map->map_str[idx] = '\0';
}

void	ft_init_map(t_game *game, char *file_name)
{
	ft_check_file_type(file_name);
	ft_count_col_and_row(&(game->map), file_name);
	ft_set_map(&(game->map), file_name, 0);
	ft_verify_map(game);
}
