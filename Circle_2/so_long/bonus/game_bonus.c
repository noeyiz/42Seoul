/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:20:55 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/08 16:47:09 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_init_game(t_game *game)
{
	int	idx;

	game->score = 0;
	game->collectible = 0;
	idx = 0;
	while (game->map.map_str[idx])
	{
		if (game->map.map_str[idx] == 'C')
			game->collectible++;
		idx++;
	}
	ft_init_player(game);
	ft_init_enemy(game);
	ft_init_pl_sprites(game);
	ft_init_en_sprites(game);
	ft_init_sc_sprites(game);
	ft_init_sprites(game);
	ft_set_sprites(game);
}

static int	ft_press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		ft_exit_game(game);
	else if (key_code == KEY_W)
		ft_move(game, Up);
	else if (key_code == KEY_A)
		ft_move(game, Left);
	else if (key_code == KEY_S)
		ft_move(game, Down);
	else if (key_code == KEY_D)
		ft_move(game, Right);
	return (0);
}

void	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map.col + 2) * SIZE, \
		(game->map.row + 4) * SIZE, "jikoo's PAC-MAN");
	ft_init_game(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &ft_press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &ft_exit_game, game);
	mlx_loop(game->mlx);
}

static void	ft_destroy_game(t_game *game)
{
	free(game->map.map_str);
	ft_destroy_sprites(game);
	ft_destroy_pl_sprites(game);
	ft_destroy_en_sprites(game);
	ft_destroy_sc_sprites(game);
}

int	ft_exit_game(t_game *game)
{
	ft_destroy_game(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	ft_putstr_fd("╔════════════════════════════════════════╗\n", 1);
	ft_putstr_fd("║                                        ║\n", 1);
	ft_putstr_fd("║      jikoo's so_long finished !!       ║\n", 1);
	ft_putstr_fd("║                                        ║\n", 1);
	ft_putstr_fd("╚════════════════════════════════════════╝\n", 1);
	exit(0);
}
