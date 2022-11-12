/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:40:18 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/10 20:38:10 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_camera(t_mlx **fdf)
{
	(*fdf)->camera.r_speed = 10.0f;
	(*fdf)->camera.p_speed = 10.0f;
	(*fdf)->camera.z_speed = 1.0f;
	(*fdf)->camera.x_angle = 0;
	(*fdf)->camera.y_angle = 0;
	(*fdf)->camera.z_angle = 0;
	(*fdf)->camera.parallel_x = 0.0f;
	(*fdf)->camera.parallel_y = 0.0f;
	(*fdf)->camera.o_scale = 15.0f;
	(*fdf)->camera.projection_type = ISOMERTIRC;
}
