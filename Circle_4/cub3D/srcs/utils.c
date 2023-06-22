/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:21:29 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:21:30 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cub_error(t_cub *cub, char *message)
{
	free_map(&cub->map_info);
	free_images(cub);
	if (cub->list)
		free_list(cub->list);
	close(cub->fd);
	printf("Error: %s\n", message);
	exit(1);
}

void	free_map(t_map_info *map)
{
	if (map->north_path)
		free(map->north_path);
	if (map->south_path)
		free(map->south_path);
	if (map->west_path)
		free(map->west_path);
	if (map->east_path)
		free(map->east_path);
	free_2d_arr(map->map);
}

void	free_images(t_cub *cub)
{
	int	idx;

	if (cub->background)
	{
		if (cub->background->img_ptr)
			mlx_destroy_image(cub->mlx_ptr, cub->background->img_ptr);
		free(cub->background);
	}
	idx = -1;
	while (++idx < 4)
	{
		if (cub->texture[idx])
		{
			if (cub->texture[idx]->img_ptr)
				mlx_destroy_image(cub->mlx_ptr, cub->texture[idx]->img_ptr);
			free(cub->texture[idx]);
		}
	}
}

void	free_2d_arr(char **arr)
{
	int	idx;

	idx = -1;
	if (arr)
	{
		while (arr[++idx])
			free(arr[idx]);
		free(arr);
	}
}

int	cub_atoi(char *str)
{
	int	num;
	int	cnt;

	num = 0;
	cnt = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
		cnt++;
	}
	while (ft_isspace(*str))
		str++;
	if (cnt == 0 || num < 0 || num > 255 || *str != '\0')
		return (-1);
	return (num);
}
