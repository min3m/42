/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:10:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 16:51:18 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	*fdf;

	if (argc != 2)
		exit (ft_putendl_fd("Error : Wrong argument", 1));
	fdf = machine_init(fdf, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit (ft_putendl_fd("Error : File open error", 1));
	fdf->map_info = read_map(fd, argv);
	draw_line(fdf);
	key_hook_event(fdf);
	return (0);
}
