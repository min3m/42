/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:45:05 by youngmch          #+#    #+#             */
/*   Updated: 2022/10/31 18:56:22 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	multiply_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	mat;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat.m[i][j] = 0;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				mat.m[i][j] += m1.m[i][k] * m2.m[k][j];
		}
	}
	return (mat);
}

t_matrix	rotate_x(int degree)
{
	static t_matrix	mat;

	mat.m[0][0] = 1;
	mat.m[1][1] = cosf(get_radian(degree));
	mat.m[1][2] = -sinf(get_radian(degree));
	mat.m[2][1] = sinf(get_radian(degree));
	mat.m[2][2] = cosf(get_radian(degree));
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	rotate_y(int degree)
{
	static t_matrix	mat;

	mat.m[0][0] = cosf(get_radian(degree));
	mat.m[0][2] = -sinf(get_radian(degree));
	mat.m[1][1] = 1;
	mat.m[2][0] = sinf(get_radian(degree));
	mat.m[2][2] = cosf(get_radian(degree));
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	rotate_z(int degree)
{
	static t_matrix	mat;

	mat.m[0][0] = cosf(get_radian(degree));
	mat.m[0][1] = -sinf(get_radian(degree));
	mat.m[1][0] = sinf(get_radian(degree));
	mat.m[1][1] = cosf(get_radian(degree));
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	return (mat);
}
