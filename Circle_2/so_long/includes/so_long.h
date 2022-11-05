/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:55:05 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/05 13:55:56 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 32

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"

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

typedef struct s_game
{
	int			cnt;
	int			collectible;
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	sprites;
	t_map		map;
}	t_game;

/* map.c */
void	ft_init_map(t_map *map, char *file_name);
void	ft_verify_map(t_map *map);

/* sprites.c */
void	ft_init_sprites(t_game *game);
void	ft_set_sprites(t_game *game);

/* move.c */
void	ft_move(t_game *game, t_direction direction);

/* game.c */
void	ft_start_game(t_game *game);
int		ft_exit_game(t_game *game);

/* utils ... */
void	ft_print_err_and_exit(char *message);

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrepl(char *str, char c1, char c2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strldup(char *str, int start, int size);

char	*ft_get_next_line(int fd);

#endif
