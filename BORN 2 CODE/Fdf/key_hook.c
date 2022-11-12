/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:13:12 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/10 20:56:26 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_rotation(int keycode, t_mlx *fdf)
{
	if (keycode == KEY_W)
		fdf->camera.x_angle += fdf->camera.r_speed;
	else if (keycode == KEY_S)
		fdf->camera.x_angle -= fdf->camera.r_speed;
	else if (keycode == KEY_D)
		fdf->camera.y_angle -= fdf->camera.r_speed;
	else if (keycode == KEY_A)
		fdf->camera.y_angle += fdf->camera.r_speed;
	else if (keycode == KEY_Q)
		fdf->camera.z_angle += fdf->camera.r_speed;
	else if (keycode == KEY_E)
		fdf->camera.z_angle -= fdf->camera.r_speed;
	draw_line(fdf);
}

void	key_parallel(int keycode, t_mlx *fdf)
{
	if (keycode == KEY_LEFT)
		fdf->camera.parallel_x -= fdf->camera.p_speed;
	else if (keycode == KEY_RIGHT)
		fdf->camera.parallel_x += fdf->camera.p_speed;
	else if (keycode == KEY_UP)
		fdf->camera.parallel_y -= fdf->camera.p_speed;
	else if (keycode == KEY_DOWN)
		fdf->camera.parallel_y += fdf->camera.p_speed;
	draw_line(fdf);
}

int	key_hook(int keycode, t_mlx *fdf)
{
	if (keycode == KEY_ECS)
		machine_exit(fdf, 0);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
	keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		key_rotation(keycode, fdf);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP \
	|| keycode == KEY_DOWN)
		key_parallel(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		key_zoom(keycode, fdf);
	else if (keycode == PARALLEL || keycode == ISOMERTIRC)
	{
		if (keycode == ISOMERTIRC)
			fdf->camera.projection_type = ISOMERTIRC;
		else if (keycode == PARALLEL)
			fdf->camera.projection_type = PARALLEL;
		draw_line(fdf);
	}
	else if (keycode == KEY_RESET)
	{
		set_camera(&fdf);
		draw_line(fdf);
	}
	return (0);
}

void	key_zoom(int keycode, t_mlx *fdf)
{
	if (keycode == KEY_PLUS)
	{
		if (fdf->camera.o_scale < 100.0f)
			fdf->camera.o_scale += fdf->camera.z_speed;
	}
	else if (keycode == KEY_MINUS)
	{
		if (fdf->camera.o_scale > 1.0f)
			fdf->camera.o_scale -= fdf->camera.z_speed;
	}
	draw_line(fdf);
}

void	key_hook_event(t_mlx *fdf)
{
	mlx_hook(fdf->win_ptr, KEY_PRESS, 0, key_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}
