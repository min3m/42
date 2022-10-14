/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:10:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/10/14 21:34:29 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int	fd;
	int	**map;

	if (argc != 2)
		return (ft_putendl_fd("Error : Wrong argument", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error : File open error", 1));
	map = read_map(fd);
	return (0);
}
