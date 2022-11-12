/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:59:13 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 15:43:12 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(t_mlx *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			my_pixel_put(&fdf->img, j, i, 0x00000000);
	}
}

void	draw_vertical(t_mlx *fdf, t_point start, t_point end, int color)
{
	int	i;

	if (end.y > start.y)
	{
		i = start.y;
		while (i < end.y && i < WIN_HEIGHT && \
		(end.x >= 0 && end.x < WIN_WIDTH))
		{
			if (i >= 0)
				my_pixel_put(&fdf->img, start.x, i, color);
			i++;
		}
	}
	else
	{
		i = end.y;
		while (i < start.y && i < WIN_HEIGHT && \
		(end.x >= 0 && end.x < WIN_WIDTH))
		{
			if (i >= 0)
				my_pixel_put(&fdf->img, start.x, i, color);
			i++;
		}
	}
}

void	draw_horizon(t_mlx *fdf, t_point start, t_point end, int color)
{
	int	i;

	if (end.x > start.x)
	{
		i = start.x;
		while (i < end.x && i < WIN_WIDTH && \
		(end.y >= 0 && end.y < WIN_HEIGHT))
		{
			if (i >= 0)
				my_pixel_put(&fdf->img, i, start.y, color);
			i++;
		}
	}
	else
	{
		i = end.x;
		while (i < start.x && i < WIN_WIDTH && \
		(end.y >= 0 && end.y < WIN_HEIGHT))
		{
			if (i >= 0)
				my_pixel_put(&fdf->img, i, start.y, color);
			i++;
		}
	}
}

void	less_one(t_mlx *fdf, t_point start, t_point end, int color)
{
	int	p;
	int	inc_x;
	int	inc_y;

	inc_x = 1;
	inc_y = 1;
	if (start.x > end.x)
		inc_x = -1;
	if (start.y > end.y)
		inc_y = -1;
	p = 2 * abs(end.x - start.x) - abs(end.y - start.y);
	while (start.x != end.x && (start.x < WIN_WIDTH && start.y < WIN_HEIGHT))
	{
		if (start.x >= 0 && start.y >= 0)
			my_pixel_put(&fdf->img, start.x, start.y, color);
		start.x += inc_x;
		if (p < 0)
			p = p + 2 * abs(end.y - start.y);
		else
		{
			p = p + 2 * abs(end.y - start.y) - 2 * abs(end.x - start.x);
			start.y += inc_y;
		}
	}
}

void	more_one(t_mlx *fdf, t_point start, t_point end, int color)
{
	int	p;
	int	inc_x;
	int	inc_y;

	inc_x = 1;
	inc_y = 1;
	if (start.x > end.x)
		inc_x = -1;
	if (start.y > end.y)
		inc_y = -1;
	p = 2 * abs(end.y - start.y) - abs(end.x - start.x);
	while (start.y != end.y && (start.x < WIN_WIDTH && start.y < WIN_HEIGHT))
	{
		if (start.x >= 0 && start.y >= 0)
			my_pixel_put(&fdf->img, start.x, start.y, color);
		start.y += inc_y;
		if (p < 0)
			p = p + 2 * abs(end.x - start.x);
		else
		{
			p = p + 2 * abs(end.x - start.x) - 2 * abs(end.y - start.y);
			start.x += inc_x;
		}
	}
}
