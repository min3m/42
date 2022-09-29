/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:27:51 by youngmch          #+#    #+#             */
/*   Updated: 2022/09/29 19:15:13 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_change(char *backup)
{
	size_t	b_len;
	size_t	i;
	char	*new;

	b_len = 0;
	i = 0;
	b_len = ft_strlen(backup);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
		i++;
	if (ft_strlen(backup) == i)
	{
		free(backup);
		return (0);
	}
	new = (char *)malloc(sizeof(char) * (b_len - i + 1));
	if (!new)
		return (0);
	ft_memmove(new, backup + i, b_len - i + 1);
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
		return (NULL);
	ft_memmove(line, backup, i);
	line[i] = 0;
	return (line);
}

static char	*ft_readtxt(int fd, char *backup, char *buf)
{
	ssize_t		temp;

	temp = 1;
	while (temp)
	{
		temp = read(fd, buf, BUFFER_SIZE);
		if (temp == -1)
			return (0);
		if (!temp)
			return (backup);
		buf[temp] = '\0';
		backup = ft_strjoin(backup, buf);
		if (ft_strchr(backup, '\n') != 0)
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	backup = ft_readtxt(fd, backup, buf);
	if (!backup)
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	line = ft_nextline(backup);
	backup = ft_change(backup);
	free(buf);
	buf = NULL;
	return (line);
}
