/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:48:16 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/15 13:17:32 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_ischar(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count(char *s, char c)
{
	int	count;
	int	len;

	count = 0;
	while (*s)
	{
		while (*s && ft_ischar(*s, c))
			s++;
		if (*s == 0)
			break ;
		len = ft_wordlen(s, c);
		s += len;
		count++;
	}
	return (count);
}

void	ft_strncpy(char *strs, char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*strs = *s;
		i++;
		strs++;
		s++;
	}
	*strs = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		len;
	int		i;

	i = -1;
	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	if (!strs)
		return (0);
	strs[ft_count((char *)s, c)] = 0;
	while (*s)
	{
		while (*s && ft_ischar(*s, c))
			s++;
		if (*s == 0)
			break ;
		len = ft_wordlen((char *)s, c);
		strs[++i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!strs[i])
			return (0);
		ft_strncpy(strs[i], (char *)s, len);
		s += len;
	}
	return (strs);
}
