/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:21:24 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 15:57:37 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	parallel(void)
{
	static t_matrix	mat;

	mat.m[0][0] = 1;
	mat.m[1][1] = 1;
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	isometric(void)
{
	static t_matrix	mat;

	mat = multiply_matrix(rotate_x(30), rotate_y(30));
	mat = multiply_matrix(rotate_z(30), mat);
	return (mat);
}
