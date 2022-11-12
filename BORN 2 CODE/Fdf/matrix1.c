/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:50:45 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 19:25:58 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	trans_point(t_point point, t_matrix mat)
{
	t_point	result;
	int		tmp[4];
	int		i;

	i = -1;
	while (++i < 4)
	{
		tmp[i] = (int)(mat.m[i][0] * point.x + mat.m[i][1] * point.y + \
				mat.m[i][2] * point.z + mat.m[i][3] * point.w);
	}
	result.x = tmp[0];
	result.y = tmp[1];
	result.z = tmp[2];
	result.w = tmp[3];
	return (result);
}

t_matrix	set_z(t_mlx *fdf)
{
	static t_matrix	mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 0.1f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_matrix	parallel_matrix1(t_mlx *fdf)
{
	static t_matrix	mat;
	int				i;

	i = -1;
	while (++i < 4)
		mat.m[i][i] = 1;
	mat.m[0][3] = -(float)fdf->map_info->x_size / 2;
	mat.m[1][3] = -(float)fdf->map_info->y_size / 2;
	return (mat);
}

t_matrix	parallel_matrix2(t_mlx *fdf)
{
	static t_matrix	mat;
	int				i;

	i = -1;
	while (++i < 4)
		mat.m[i][i] = 1;
	mat.m[0][3] = (float)WIN_WIDTH / 2 + fdf->camera.parallel_x;
	mat.m[1][3] = (float)WIN_HEIGHT / 2 + fdf->camera.parallel_y;
	return (mat);
}

t_matrix	scale_matrix(t_mlx *fdf)
{
	static t_matrix	mat;

	mat.m[0][0] = fdf->camera.o_scale;
	mat.m[1][1] = fdf->camera.o_scale;
	mat.m[2][2] = fdf->camera.o_scale;
	mat.m[3][3] = 1.0f;
	return (mat);
}
