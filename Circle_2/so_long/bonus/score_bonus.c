/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:22 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/12 16:43:41 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_sc_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sc_sprites.zero = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/0.xpm", &width, &height);
	game->sc_sprites.one = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/1.xpm", &width, &height);
	game->sc_sprites.two = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/2.xpm", &width, &height);
	game->sc_sprites.three = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/3.xpm", &width, &height);
	game->sc_sprites.four = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/4.xpm", &width, &height);
	game->sc_sprites.five = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/5.xpm", &width, &height);
	game->sc_sprites.six = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/6.xpm", &width, &height);
	game->sc_sprites.seven = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/7.xpm", &width, &height);
	game->sc_sprites.eight = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/8.xpm", &width, &height);
	game->sc_sprites.nine = mlx_xpm_file_to_image(game->mlx, \
		"sprites/Other/Fonts/9.xpm", &width, &height);
}

static void	*ft_get_sc_sprite(t_game *game, int n)
{
	if (n == 0)
		return (game->sc_sprites.zero);
	else if (n == 1)
		return (game->sc_sprites.one);
	else if (n == 2)
		return (game->sc_sprites.two);
	else if (n == 3)
		return (game->sc_sprites.three);
	else if (n == 4)
		return (game->sc_sprites.four);
	else if (n == 5)
		return (game->sc_sprites.five);
	else if (n == 6)
		return (game->sc_sprites.six);
	else if (n == 7)
		return (game->sc_sprites.seven);
	else if (n == 8)
		return (game->sc_sprites.eight);
	else if (n == 9)
		return (game->sc_sprites.nine);
	return (0);
}

void	ft_put_score_image(t_game *game)
{
	int	i;
	int	score;

	i = 0;
	score = game->score;
	while (++i <= 4)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.black, \
		((game->map.col / 2) + 3 - i) * SIZE, (game->map.row + 2) * SIZE);
		mlx_put_image_to_window(game->mlx, game->win, \
		ft_get_sc_sprite(game, score % 10), \
		((game->map.col / 2) + 3 - i) * SIZE, (game->map.row + 2) * SIZE);
		score /= 10;
	}
}
