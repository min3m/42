/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:14:31 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/13 19:21:21 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ISOMERTIRC 18
# define PARALLEL 19

/* KEY HOOKING */

# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define KEY_ECS 53
# define KEY_RESET 15

/* X ROTATION */

# define KEY_A 0
# define KEY_D 2

/* Y ROTATION */

# define KEY_W 13
# define KEY_S 1

/* Z ROTATION */

# define KEY_Q 12
# define KEY_E 14

/* PARALLEL MOVE */

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/* ZOOM */

# define KEY_PLUS 24
# define KEY_MINUS 27

typedef struct s_move{
	int		r_speed;
	float	p_speed;
	float	z_speed;
	int		x_angle;
	int		y_angle;
	int		z_angle;
	float	o_scale;
	float	parallel_x;
	float	parallel_y;
	int		projection_type;
}				t_move;

typedef struct s_point{
	int	x;
	int	y;
	int	z;
	int	w;
	int	color;
}				t_point;

typedef struct s_map
{
	int		x_size;
	int		y_size;
	t_point	**map;
}				t_map;

typedef struct s_matrix
{
	float	m[4][4];
}				t_matrix;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	t_map	*map_info;
	t_move	camera;
}				t_mlx;

int			main(int argc, char **argv);
/* READ MAP */
t_map		*read_map(t_mlx *fdf, int fd, char **argv);
void		y_malloc(t_mlx *fdf, int fd, t_map **map);
void		free_all(char *line, char **line_split);
void		fill_map(t_mlx *fdf, int tmp, t_map **map);
void		map_atoi(t_map **map, char **line_split, int y);
/* MACHINE INIT */
t_mlx		*machine_init(t_mlx *fdf, char *argv);
void		machine_exit(t_mlx *fdf, int flag);
/* DRAWING LINE */
void		draw_line(t_mlx *fdf);
t_matrix	apply_matrix(t_mlx *fdf);
void		my_pixel_put(t_data *img, int x, int y, int color);
void		draw_vertical(t_mlx *fdf, t_point start, t_point end, int color);
void		draw_horizon(t_mlx *fdf, t_point start, t_point end, int color);
void		less_one(t_mlx *fdf, t_point start, t_point end, int color);
void		more_one(t_mlx *fdf, t_point start, t_point end, int color);
void		bresenham(t_mlx *fdf, t_point start, t_point end, int color);
void		draw_background(t_mlx *fdf);
/* SET MARTRIX */
t_matrix	set_z(t_mlx *fdf);
t_matrix	scale_matrix(t_mlx *fdf);
t_matrix	parallel_matrix1(t_mlx *fdf);
t_matrix	parallel_matrix2(t_mlx *fdf);
t_point		trans_point(t_point point, t_matrix mat);
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2);
t_matrix	rotate_x(int degree);
t_matrix	rotate_y(int degree);
t_matrix	rotate_z(int degree);
/* projection */
t_matrix	parallel(void);
t_matrix	isometric(void);
/* HOOKING */
void		key_hook_event(t_mlx *fdf);
int			key_hook(int keycode, t_mlx *fdf);
void		key_rotation(int keycode, t_mlx *fdf);
void		key_parallel(int keycode, t_mlx *fdf);
void		key_zoom(int keycode, t_mlx *fdf);
/* SET CAMERA */
void		set_camera(t_mlx **fdf);
/* UTILL */
int			get_addnum(int num);
float		get_radian(int degree);
int			count_line(char **line_split);

#endif
