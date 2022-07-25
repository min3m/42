/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:43:58 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/31 14:16:52 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_point(unsigned long long point, int i)
{
	if (point == 0 && i > 16)
		return ;
	i++;
	ft_point(point / 16, i);
	if (point != 0)
		write(1, &"0123456789abcdef"[point % 16], 1);
	else
		write(1, "0", 1);
}

void	ft_hex(char *s1, unsigned int i)
{
	unsigned int	k;
	unsigned int	j;
	int				h;

	j = i;
	while (s1[j] != 0 && j < i + 16)
		j++;
	k = i;
	while (k < i + 16)
	{
		h = s1[k];
		if (k <= j)
		{
			write(1, &"0123456789abcdef"[h / 16], 1);
			write(1, &"0123456789abcdef"[h % 16], 1);
		}
		else
			write(1, "  ", 2);
		if ((k + 1) % 2 == 0)
			write(1, " ", 1);
		k++;
	}
}

void	ft_print(char *s2, unsigned int i)
{
	unsigned int	l;
	int				k;

	l = i;
	k = 0;
	while (l < i + 16)
	{
		if (s2[l] < 32 || s2[l] >= 127)
		{
			write(1, ".", 1);
			if (s2[l] == 0)
				break ;
		}
		else
			write(1, &s2[l], 1);
		l++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned long long	p;
	char				*str;

	str = (char *)addr;
	i = 0;
	j = 1;
	while (i < size)
	{
		p = (unsigned long long)(str + i);
		ft_point(p, 1);
		write(1, ": ", 2);
		ft_hex(str, i);
		ft_print(str, i);
		write(1, "\n", 1);
		i += 16;
	}
	return (0);
}
