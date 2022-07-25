/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:55:34 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/07 18:08:03 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *src, int len)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p;
	int			i;
	int			j;

	i = 0;
	j = -1;
	p = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!p)
		return (0);
	while (i < ac)
	{
		p[i].size = ft_len(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strcpy(av[i], p[i].size);
		i++;
	}
	p[i].str = 0;
	p[i].copy = 0;
	p[i].size = 0;
	return (p);
}
