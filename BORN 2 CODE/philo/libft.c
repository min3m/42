/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:55:23 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/01 21:16:16 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	return (1);
}

static int	ft_isspace(const char *nptr, int i)
{
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

static bool	matoi(const char *nptr, int *num)
{
	int	sign;
	int	i;

	sign = -1;
	i = ft_isspace(nptr, 0);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_is_digit(nptr[i]))
		return (false);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		*num = *num * 10 - (nptr[i] - '0');
		i++;
	}
	if (nptr[i])
		return (false);
	*num = *num * sign;
	return (true);
}
