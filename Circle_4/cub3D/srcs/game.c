/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:21:01 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:21:02 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	exit_game(t_cub *cub)
{
	free_map(&cub->map_info);
	free_images(cub);
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	exit(0);
}

static void	move(t_cub *cub, t_vector dir_vec)
{
	double	changed_x;
	double	changed_y;

	changed_x = cub->player.pos.x + dir_vec.x * MV_SPEED;
	changed_y = cub->player.pos.y + dir_vec.y * MV_SPEED;
	if (cub->map_info.map[(int)(changed_x - 0.2)][(int)(changed_y - 0.2)] == '1'
	|| cub->map_info.map[(int)(changed_x + 0.2)][(int)(changed_y + 0.2)] == '1'
	|| cub->map_info.map[(int)(changed_x + 0.2)][(int)(changed_y - 0.2)] == '1'
	|| cub->map_info.map[(int)(changed_x - 0.2)][(int)(changed_y + 0.2)] == '1')
		return ;
	cub->player.pos.x = changed_x;
	cub->player.pos.y = changed_y;
	raycast(cub);
}

static void	rotate(t_cub *cub, int circle_dir)
{
	cub->player.dir = get_rotated_vector(cub->player.dir, M_PI / 18
			* circle_dir);
	cub->player.plane = get_rotated_vector(cub->player.plane, M_PI / 18
			* circle_dir);
	raycast(cub);
}

static int	press_key(int key_code, t_cub *cub)
{
	if (key_code == KEY_ESC)
		exit_game(cub);
	else if (key_code == KEY_W)
		move(cub, cub->player.dir);
	else if (key_code == KEY_A)
		move(cub, get_rotated_vector(cub->player.dir, M_PI / 2));
	else if (key_code == KEY_S)
		move(cub, get_rotated_vector(cub->player.dir, M_PI));
	else if (key_code == KEY_D)
		move(cub, get_rotated_vector(cub->player.dir, M_PI * 3 / 2));
	else if (key_code == KEY_LEFT)
		rotate(cub, 1);
	else if (key_code == KEY_RIGHT)
		rotate(cub, -1);
	return (0);
}

void	start_game(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	init_player(cub);
	init_images(cub);
	raycast(cub);
	mlx_hook(cub->win_ptr, X_EVENT_KEY_PRESS, 0, &press_key, cub);
	mlx_hook(cub->win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, cub);
	mlx_loop(cub->mlx_ptr);
}
