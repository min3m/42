/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:55:23 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/18 20:34:13 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
	return (1);
}

int	ft_isspace(const char *nptr, int i)
{
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

bool	matoi(const char *nptr, int *num)
{
	int		i;
	size_t	temp;

	temp = (size_t)(*num);
	i = ft_isspace(nptr, 0);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			return (false);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		temp = temp * 10 + (nptr[i] - '0');
		i++;
		if (temp > INT_MAX)
			return (false);
	}
	if (nptr[i])
		return (false);
	*num = (int)temp;
	return (true);
}

uint64_t	get_ms_time(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + val.tv_usec / 1000);
}
