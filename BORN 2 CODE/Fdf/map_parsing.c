/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:13:34 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 17:43:46 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(char *line, char **line_split)
{
	int	i;

	i = 0;
	free(line);
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
}

void	map_atoi(t_map **map, char **line_split, int y)
{
	int		i;
	char	*color;

	i = 0;
	while (line_split[i])
	{
		(*map)->map[y][i].x = i;
		(*map)->map[y][i].y = y;
		(*map)->map[y][i].z = ft_atoi(line_split[i]);
		(*map)->map[y][i].w = 1;
		color = ft_strchr(line_split[i], ',');
		if (color)
			(*map)->map[y][i].color = ft_atoi_base(color + 3);
		else
			(*map)->map[y][i].color = 0x00FFFFFF;
		i++;
	}
}

void	fill_map(int fd, t_map **map)
{
	int		y;
	char	*line;
	char	**line_split;

	y = 0;
	while (y < (*map)->y_size)
	{
		line = get_next_line(fd);
		line_split = ft_split(line, ' ');
		if (!line_split)
		{
			free_all(line, line_split);
			exit(ft_putendl_fd("Error : Split error", 1));
		}
		(*map)->x_size = count_line(line_split);
		(*map)->map[y] = (t_point *)malloc(sizeof(t_point) * (*map)->x_size);
		if (!(*map)->map[y])
		{
			free_all(line, line_split);
			exit(ft_putendl_fd("Error : Malloc error", 1));
		}
		map_atoi(map, line_split, y++);
		free_all(line, line_split);
	}
}

void	y_malloc(int fd, t_map **map)
{
	char	*line;

	(*map)->y_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		(*map)->y_size++;
		free(line);
		line = get_next_line(fd);
	}
	(*map)->map = (t_point **)malloc(sizeof(t_point *) * (*map)->y_size);
	if (!((*map)->map))
		exit(ft_putendl_fd("Error : Malloc error", 1));
}

t_map	*read_map(int fd, char **argv)
{
	int		tmp;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(ft_putendl_fd("Error : Malloc error", 1));
	y_malloc(fd, &map);
	close(fd);
	tmp = open(argv[1], O_RDONLY);
	if (tmp < 0)
	{
		free(map);
		exit(ft_putendl_fd("Error : File open error", 1));
	}
	fill_map(tmp, &map);
	close(tmp);
	return (map);
}
