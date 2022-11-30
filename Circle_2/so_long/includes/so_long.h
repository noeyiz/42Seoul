/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:56:11 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/30 16:14:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* mlx */
# include "../mlx/mlx.h"
/* libft */
# include "../libft/libft.h"
/* get_next_line */
# include "../gnl/get_next_line.h"

# define SIZE 32

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef enum e_direction
{
	Up,
	Down,
	Left,
	Right			
}	t_direction;

typedef struct s_sprite
{
	void	*black;
	void	*pacfood;
	void	*pacman;
	void	*portal;
	void	*wall;
}	t_sprite;

typedef struct s_map
{
	int		col;
	int		row;
	char	*map_str;
}	t_map;

typedef struct s_check_map
{
	int	pl_col;
	int	pl_row;
	int	collectible;
	int	exit;
	int	*check;	
}	t_check_map;

typedef struct s_game
{
	int			cnt;
	int			collectible;
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	sprites;
	t_map		map;
	t_check_map	check_map;
}	t_game;

/* map */
void	ft_init_map(t_game *game, char *file_name);
void	ft_verify_map(t_game *game);
void	ft_check_valid_path(t_game *game);

/* sprites */
void	ft_init_sprites(t_game *game);
void	ft_set_sprites(t_game *game);

/* move */
void	ft_move(t_game *game, t_direction direction);

/* game */
void	ft_start_game(t_game *game);
int		ft_exit_game(t_game *game);

/* utils */
void	ft_print_err(char *message);
char	*ft_strrepl(char *str, char c1, char c2);

#endif