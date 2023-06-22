/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:20:58 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:20:59 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	put_pixel_to_img(int idx, t_ray *ray,
	t_img *texture, unsigned int *img_buf)
{
	int		texture_x;
	int		texture_y;
	double	texture_pos;
	double	step;

	texture_x = (int)(ray->wall_x * (double)texture->width);
	if ((ray->side == VERTICAL && ray->dx > 0)
		|| (ray->side == HORIZONTAL && ray->dy < 0))
		texture_x = texture->width - texture_x - 1;
	step = 1.0 * texture->height / ray->wall_height;
	texture_pos = (ray->draw_start - HEIGHT / 2 + ray->wall_height / 2) * step;
	while (ray->draw_start <= ray->draw_end)
	{
		texture_y = (int)texture_pos;
		texture_pos += step;
		if (texture_y < texture->height)
			img_buf[WIDTH * ray->draw_start + idx]
				= texture->buffer[texture->width * texture_y + texture_x];
		ray->draw_start++;
	}
}

void	set_transparent_img(unsigned int *buffer)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			buffer[WIDTH * i + j] = 0xff000000;
	}
}

void	draw_vertical_pixel(t_cub *cub, t_ray *ray, t_img *img, int idx)
{
	ray->draw_start = -ray->wall_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0.0;
	ray->draw_end = ray->wall_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1.0;
	if (ray->side == HORIZONTAL && ray->dy == -1)
		put_pixel_to_img(idx, ray, cub->texture[WEST], img->buffer);
	else if (ray->side == HORIZONTAL && ray->dy == 1)
		put_pixel_to_img(idx, ray, cub->texture[EAST], img->buffer);
	else if (ray->side == VERTICAL && ray->dx == 1)
		put_pixel_to_img(idx, ray, cub->texture[SOUTH], img->buffer);
	else if (ray->side == VERTICAL && ray->dx == -1)
		put_pixel_to_img(idx, ray, cub->texture[NORTH], img->buffer);
}
