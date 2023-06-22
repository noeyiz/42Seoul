/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:20:51 by jikoo             #+#    #+#             */
/*   Updated: 2023/06/17 21:20:52 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIDTH				1280
# define HEIGHT				920
# define FOV				0.66
# define MV_SPEED			0.1

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_W 				13
# define KEY_A 				0
# define KEY_S 				1
# define KEY_D 				2
# define KEY_LEFT			123
# define KEY_RIGHT			124

typedef struct s_cub		t_cub;
typedef struct s_map_info	t_map_info;
typedef struct s_list		t_list;
typedef struct s_player		t_player;
typedef struct s_vector		t_vector;
typedef struct s_ray		t_ray;
typedef struct s_texture	t_texture;
typedef struct s_img		t_img;
typedef enum e_side			t_side;
typedef enum e_element		t_element;

enum e_element
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEILING
};

enum e_side
{
	HORIZONTAL,
	VERTICAL
};

struct s_vector
{
	double	x;
	double	y;
};

struct s_list
{
	char	*line;
	t_list	*next;
};

struct s_img
{
	void			*img_ptr;
	unsigned int	*buffer;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
};

struct s_map_info
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	unsigned int	color_floor;
	unsigned int	color_ceiling;
	char			**map;
	int				width;
	int				height;
	int				check[6];
};

struct s_ray
{
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	dir;
	t_side		side;
	int			map_x;
	int			map_y;
	int			dx;
	int			dy;
	int			hit;
	int			wall_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
};

struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	char		direction;
};

struct s_cub
{
	int			fd;
	int			error;
	void		*mlx_ptr;
	void		*win_ptr;
	t_list		*list;
	t_player	player;
	t_map_info	map_info;
	t_img		*background;
	t_img		*texture[4];
};

/* init */
void		init_map(t_cub *cub, char *filename);
void		init_images(t_cub *cub);
void		init_player(t_cub *cub);

/* map */
void		parse_map_element(t_cub *cub);
void		parse_map(t_cub *cub);
void		check_map(t_cub *cub);

/* draw */
void		set_transparent_img(unsigned int *buffer);
void		draw_vertical_pixel(t_cub *cub, t_ray *ray, t_img *img, int idx);

/* raycast */
void		raycast(t_cub *cub);

/* game */
void		start_game(t_cub *cub);

/* list */
t_list		*make_node(char *line);
void		add_back_list(t_list **list, char *line);
void		free_list(t_list *list);

/* vector */
t_vector	get_vector(int x, int y);
t_vector	get_rotated_vector(t_vector origin, double angle);

/* map_utils.c */
int			is_movable(char position);
int			get_direction(int idx);
int			is_empty_line(char *line);

/* utils */
void		cub_error(t_cub *cub, char *message);
void		free_map(t_map_info *map);
void		free_images(t_cub *cub);
int			cub_atoi(char *str);
void		free_2d_arr(char **arr);

#endif
