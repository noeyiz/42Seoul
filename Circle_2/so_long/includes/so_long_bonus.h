/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:31 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/08 16:46:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	Left,
	Down,
	Right,
	Stop
}	t_direction;

typedef struct s_sc_sprites
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}	t_sc_sprites;

typedef struct s_pl_sprites
{
	void	*closed;
	void	*up;
	void	*up_semi;
	void	*left;
	void	*left_semi;
	void	*down;
	void	*down_semi;
	void	*right;
	void	*right_semi;
}	t_pl_sprites;

typedef struct s_en_sprites
{
	void	*up1;
	void	*up2;
	void	*left1;
	void	*left2;
	void	*down1;
	void	*down2;
	void	*right1;
	void	*right2;
}	t_en_sprites;

typedef struct s_sprites
{
	void	*black;
	void	*pacfood;
	void	*portal;
	void	*wall;
}	t_sprites;

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

typedef struct s_player
{
	int			col;
	int			row;
	int			x;
	int			y;
	t_direction	direction;
}	t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	t_direction	direction;
}	t_enemy;

typedef struct s_game
{
	int				score;
	int				collectible;
	void			*mlx;
	void			*win;
	t_sc_sprites	sc_sprites;
	t_pl_sprites	pl_sprites;
	t_en_sprites	en_sprites;
	t_sprites		sprites;
	t_map			map;
	t_check_map		check_map;
	t_player		player;
	t_enemy			enemy;
}	t_game;

/* map */
void	ft_init_map(t_game *game, char *file_name);
void	ft_verify_map(t_game *game);
void	ft_check_valid_path(t_game *game);

/* score */
void	ft_init_sc_sprites(t_game *game);
void	ft_destroy_sc_sprites(t_game *game);
void	ft_put_score_image(t_game *game);

/* player */
void	ft_init_player(t_game *game);
void	ft_init_pl_sprites(t_game *game);
void	ft_destroy_pl_sprites(t_game *game);
void	*ft_get_pl_sprite(t_game *game);
void	ft_put_player_image(t_game *game);

/* enemy */
void	ft_init_enemy(t_game *game);
void	ft_init_en_sprites(t_game *game);
void	ft_destroy_en_sprites(t_game *game);
void	*ft_get_en_sprite(t_game *game);
void	ft_put_enemy_image(t_game *game);

/* sprites */
void	ft_init_sprites(t_game *game);
void	ft_destroy_sprites(t_game *game);
void	ft_set_sprites(t_game *game);

/* move */
void	ft_move(t_game *game, t_direction direction);

/* move_enemy */
void	ft_move_enemy(t_game *game);

/* game */
void	ft_start_game(t_game *game);
int		ft_exit_game(t_game *game);

/* utils */
void	ft_print_err(char *message);
int		ft_abs(int n, int m);
char	*ft_strrepl(char *str, char c1, char c2);

#endif
