/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:04:17 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 15:46:35 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_mlx *fdf, t_point start, t_point end, int color)
{
	int	i;

	if (end.x - start.x == 0)
		draw_vertical(fdf, start, end, color);
	else if (end.y - start.y == 0)
		draw_horizon(fdf, start, end, color);
	else if (abs(end.y - start.y) < abs(end.x - start.x))
		less_one(fdf, start, end, color);
	else
		more_one(fdf, start, end, color);
}

t_matrix	apply_matrix(t_mlx *fdf)
{
	t_matrix	mat;

	mat = set_z(fdf);
	mat = multiply_matrix(parallel_matrix1(fdf), mat);
	mat = multiply_matrix(scale_matrix(fdf), mat);
	mat = multiply_matrix(rotate_x(fdf->camera.x_angle), mat);
	mat = multiply_matrix(rotate_y(fdf->camera.y_angle), mat);
	mat = multiply_matrix(rotate_z(fdf->camera.z_angle), mat);
	if (fdf->camera.projection_type == ISOMERTIRC)
		mat = multiply_matrix(isometric(), mat);
	else if (fdf->camera.projection_type == PARALLEL)
		mat = multiply_matrix(parallel(), mat);
	mat = multiply_matrix(parallel_matrix2(fdf), mat);
	return (mat);
}

void	draw_line(t_mlx *fdf)
{
	int			i;
	int			j;
	t_matrix	mat;

	i = 0;
	mat = apply_matrix(fdf);
	draw_background(fdf);
	while (i < fdf->map_info->y_size)
	{
		j = 0;
		while (j < fdf->map_info->x_size)
		{
			if (j < fdf->map_info->x_size - 1)
				bresenham(fdf, trans_point(fdf->map_info->map[i][j], mat), \
						trans_point(fdf->map_info->map[i][j + 1], mat), \
						fdf->map_info->map[i][j].color);
			if (i < fdf->map_info->y_size - 1)
				bresenham(fdf, trans_point(fdf->map_info->map[i][j], mat), \
						trans_point(fdf->map_info->map[i + 1][j], mat), \
						fdf->map_info->map[i][j].color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
}
