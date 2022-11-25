/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:57:53 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/25 13:48:09 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_file_type(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".ber"))
		ft_print_err_and_exit("Error\nInvalid file type, use .ber!");
}

static void	ft_count_col_and_row(t_map *map, char *file_name)
{
	int		fd;
	int		cur_col;
	char	buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_err_and_exit("Error\nFile not found!");
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
		ft_print_err_and_exit("Error\nMemory allocation error!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_err_and_exit("Error\nFile not found!");
	cur_row = 0;
	while (cur_row < map->row)
	{
		line = ft_strrepl(ft_get_next_line(fd), '\n', '\0');
		cur_col = 0;
		while (cur_col < ft_strlen(line))
		{
			map->map_str[idx++] = line[cur_col];
			cur_col++;
		}
		cur_row++;
	}
	map->map_str[idx] = '\0';
	close(fd);
}

void	ft_init_map(t_map *map, char *file_name)
{
	ft_check_file_type(file_name);
	ft_count_col_and_row(map, file_name);
	ft_set_map(map, file_name, 0);
	ft_verify_map(map);
}
