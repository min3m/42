/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:13:34 by youngmch          #+#    #+#             */
/*   Updated: 2022/10/14 21:44:32 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**read_map(int fd)
{
	char	*line;
	char	**line_split;

	line = get_next_line(fd);
	while (!line)
	{
		line_split = ft_split(line, ' ');
		if (!line_split)
		{
			free_split(line_split);
			return (ft_putendl_fd("Error : Split error", 1));
		}
		line = get_next_line(fd);
	}
}
