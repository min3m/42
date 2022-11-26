/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:47 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 17:18:35 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_mlx *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map_info->y_size)
	{
		free(fdf->map_info->map[i]);
		i++;
	}
	free(fdf->map_info->map);
	free(fdf->map_info);
}

void	machine_exit(t_mlx *fdf, int flag)
{
	if (fdf && fdf->img.img)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	if (fdf && fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf && fdf->mlx_ptr)
		free(fdf->mlx_ptr);
	if (fdf && fdf->map_info)
		free_map(fdf);
	if (fdf)
		free(fdf);
	if (flag)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

t_mlx	*machine_init(t_mlx *fdf, char *argv)
{
	fdf = (t_mlx *)malloc(sizeof(t_mlx));
	if (!fdf)
		machine_exit(fdf, 1);
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		machine_exit(fdf, 1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, argv);
	if (!fdf->win_ptr)
		machine_exit (fdf, 1);
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
	&fdf->img.line_size, &fdf->img.endian);
	set_camera(&fdf);
	return (fdf);
}
