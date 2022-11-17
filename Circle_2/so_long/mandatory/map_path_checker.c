/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:49:00 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/17 21:03:18 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_set_check_str(t_game *game)
{
	int	i;

	game->check_map.check = (int *)malloc(sizeof(int) * (ft_strlen(game->map.map_str)));
	if (!game->check_map.check)
		ft_print_err_and_exit("Memory allocation error!");
	i = 0;
	while (game->map.map_str[i])
	{
		game->check_map.check[i] = 0;
		if (game->map.map_str[i] == 'P')
			game->check_map.check[i] = 1;
		i++;
	}
}

static void	ft_check_all_path(t_game *game, int idx)
{
	if (game->map.map_str[idx] != '1')
	{
		game->check_map.check[idx] += 1;
		ft_check_all_path(game, idx - game->map.col);
		ft_check_all_path(game, idx - 1);
		ft_check_all_path(game, idx + game->map.col);
		ft_check_all_path(game, idx + 1);
	}
	else
		return ;
}

void	ft_check_valid_path(t_game *game)
{
	int	i;

	ft_set_check_str(game);
	printf("%d\n", game->check_map.pl_idx);
	ft_check_all_path(game, game->check_map.pl_idx);
	i = 0;
	while (i < ft_strlen(game->map.map_str))
	{
		printf("%d", game->check_map.check[i]);
		i++;
	}
}
