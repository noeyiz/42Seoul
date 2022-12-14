/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:11:13 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/08 15:43:14 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_set_check_map(t_game *game, char mode)
{
	int	col;
	int	row;

	game->check_map.check = (int *)malloc(sizeof(int) * \
	ft_strlen(game->map.map_str));
	if (!game->check_map.check)
		ft_print_err("Memory allocation error!");
	row = -1;
	while (row++ < game->map.row)
	{
		col = 0;
		while (game->map.map_str[row * game->map.col + col])
		{
			game->check_map.check[row * game->map.col + col] = 0;
			if (game->map.map_str[row * game->map.col + col] == 'P')
			{
				game->check_map.pl_col = col;
				game->check_map.pl_row = row;
			}
			else if (game->map.map_str[row * game->map.col + col] == '1' \
			|| game->map.map_str[row * game->map.col + col] == mode)
				game->check_map.check[row * game->map.col + col] = 2;
			col++;
		}
	}
}

static void	ft_floodfill(int col, int row, t_game *game)
{
	int	idx;

	idx = row * game->map.col + col;
	if (col >= game->map.col || row >= game->map.row || col < 0 || row < 0 \
	|| game->check_map.check[idx] != 0)
		return ;
	game->check_map.check[idx] = 1;
	if (game->map.map_str[idx] == 'C')
		game->check_map.collectible--;
	else if (game->map.map_str[idx] == 'E')
		game->check_map.exit--;
	ft_floodfill(col + 1, row, game);
	ft_floodfill(col - 1, row, game);
	ft_floodfill(col, row + 1, game);
	ft_floodfill(col, row - 1, game);
}

void	ft_check_valid_path(t_game *game)
{
	ft_set_check_map(game, 'E');
	ft_floodfill(game->check_map.pl_col, game->check_map.pl_row, game);
	if (game->check_map.collectible)
		ft_print_err("Not a valid path!");
	free(game->check_map.check);
	ft_set_check_map(game, '1');
	ft_floodfill(game->check_map.pl_col, game->check_map.pl_row, game);
	if (game->check_map.exit)
		ft_print_err("Not a valid path!");
	free(game->check_map.check);
}
