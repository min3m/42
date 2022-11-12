/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:36:29 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 17:33:13 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_change(char *backup)
{
	size_t	b_len;
	size_t	i;
	char	*new;

	b_len = 0;
	i = 0;
	b_len = gnl_strlen(backup);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
		i++;
	if (gnl_strlen(backup) == i)
	{
		free(backup);
		backup = NULL;
		return (0);
	}
	new = (char *)malloc(sizeof(char) * (b_len - i + 1));
	if (!new)
		exit(EXIT_FAILURE);
	gnl_memmove(new, backup + i, b_len - i + 1);
	free(backup);
	backup = NULL;
	return (new);
}

static char	*ft_nextline(char *backup)
{
	char	*line;
	size_t	i;

	i = 0;
	while (backup[i] != '\n' && backup[i] != 0)
		i++;
	if (backup[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		exit(EXIT_FAILURE);
	gnl_memmove(line, backup, i);
	line[i] = 0;
	return (line);
}

static char	*ft_readtxt(int fd, char *backup, char *buf)
{
	int		temp;

	temp = 1;
	while (temp)
	{
		temp = read(fd, buf, BUFFER_SIZE);
		if (temp == -1)
		{
			free(buf);
			buf = NULL;
			exit(EXIT_FAILURE);
		}
		if (!temp)
			return (backup);
		buf[temp] = '\0';
		backup = gnl_strjoin(backup, buf);
		if (gnl_strchr(backup, '\n') != 0)
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		exit(EXIT_FAILURE);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		exit(EXIT_FAILURE);
	backup[fd] = ft_readtxt(fd, backup[fd], buf);
	if (!backup[fd])
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	line = ft_nextline(backup[fd]);
	backup[fd] = ft_change(backup[fd]);
	free(buf);
	buf = NULL;
	return (line);
}
