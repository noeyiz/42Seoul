/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:21:05 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/21 14:44:39 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map(t_cub *cub, char *filename)
{
	if (ft_strlen(filename) < 5
		|| ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 5))
		cub_error(cub, "Invalid file type, use .cub!");
	cub->fd = open(filename, O_RDONLY);
	if (cub->fd == -1)
		cub_error(cub, "File not found");
	parse_map_element(cub);
	parse_map(cub);
	check_map(cub);
	close(cub->fd);
}

void	init_player(t_cub *cub)
{
	cub->player.pos.x += 0.5;
	cub->player.pos.y += 0.5;
	if (cub->player.direction == 'N')
		cub->player.dir = get_vector(-1, 0);
	else if (cub->player.direction == 'W')
		cub->player.dir = get_vector(0, -1);
	else if (cub->player.direction == 'S')
		cub->player.dir = get_vector(1, 0);
	else if (cub->player.direction == 'E')
		cub->player.dir = get_vector(0, 1);
	cub->player.plane = get_rotated_vector(cub->player.dir, M_PI * 3 / 2);
	cub->player.plane.x *= FOV;
	cub->player.plane.y *= FOV;
}

static t_img	*get_background_img(t_cub *cub)
{
	t_img	*img;
	int		i;
	int		j;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(cub->mlx_ptr, WIDTH, HEIGHT);
	img->buffer = (unsigned int *)mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			if (i < HEIGHT / 2)
				img->buffer[WIDTH * i + j] = cub->map_info.color_ceiling;
			else
				img->buffer[WIDTH * i + j] = cub->map_info.color_floor;
		}
	}
	return (img);
}

static t_img	*get_texture_img(t_cub *cub, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, path,
			&(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->buffer = (unsigned int *)mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	return (img);
}

void	init_images(t_cub *cub)
{
	cub->background = get_background_img(cub);
	cub->texture[NORTH] = get_texture_img(cub, cub->map_info.north_path);
	cub->texture[SOUTH] = get_texture_img(cub, cub->map_info.south_path);
	cub->texture[EAST] = get_texture_img(cub, cub->map_info.east_path);
	cub->texture[WEST] = get_texture_img(cub, cub->map_info.west_path);
	if (cub->background == NULL
		|| cub->texture[NORTH] == NULL || cub->texture[SOUTH] == NULL
		|| cub->texture[EAST] == NULL || cub->texture[WEST] == NULL)
		cub_error(cub, "Init image failed");
}
