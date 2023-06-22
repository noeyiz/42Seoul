/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:21:26 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:21:27 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_ray_side_dist(t_cub *cub, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->dx = -1;
		ray->side_dist.x = (cub->player.pos.x - ray->map_x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->dx = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - cub->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->dy = -1;
		ray->side_dist.y = (cub->player.pos.y - ray->map_y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->dy = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - cub->player.pos.y)
			* ray->delta_dist.y;
	}
}

static void	init_ray(t_cub *cub, t_ray *ray, int idx)
{
	double	plane_idx;

	ft_memset(ray, 0, sizeof(t_ray));
	plane_idx = 2 * idx / (double)WIDTH - 1;
	ray->dir.x = cub->player.dir.x + cub->player.plane.x * plane_idx;
	ray->dir.y = cub->player.dir.y + cub->player.plane.y * plane_idx;
	ray->map_x = (int)cub->player.pos.x;
	ray->map_y = (int)cub->player.pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	init_ray_side_dist(cub, ray);
}

static void	dda(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->dx;
			ray->side = VERTICAL;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->dy;
			ray->side = HORIZONTAL;
		}
		if (cub->map_info.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

static void	set_wall_element(t_cub *cub, t_ray *ray)
{
	double	perpendicular_dist;

	if (ray->side == VERTICAL)
	{
		perpendicular_dist = (ray->map_x - cub->player.pos.x
				+ (1 - ray->dx) / 2) / ray->dir.x;
		ray->wall_height = (int)(HEIGHT / perpendicular_dist);
		ray->wall_x = cub->player.pos.y + perpendicular_dist * ray->dir.y;
	}
	else
	{
		perpendicular_dist = (ray->map_y - cub->player.pos.y
				+ (1 - ray->dy) / 2) / ray->dir.y;
		ray->wall_height = (int)(HEIGHT / perpendicular_dist);
		ray->wall_x = cub->player.pos.x + perpendicular_dist * ray->dir.x;
	}
	ray->wall_x -= (int)ray->wall_x;
}

void	raycast(t_cub *cub)
{
	t_img	img;
	t_ray	ray;
	int		idx;

	img.img_ptr = mlx_new_image(cub->mlx_ptr, WIDTH, HEIGHT);
	img.buffer = (unsigned int *)mlx_get_data_addr(img.img_ptr,
			&(img.bits_per_pixel), &(img.size_line), &(img.endian));
	set_transparent_img(img.buffer);
	idx = -1;
	while (++idx < WIDTH)
	{
		init_ray(cub, &ray, idx);
		dda(cub, &ray);
		set_wall_element(cub, &ray);
		draw_vertical_pixel(cub, &ray, &img, idx);
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
		cub->background->img_ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, img.img_ptr, 0, 0);
}
