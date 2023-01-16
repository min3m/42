/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:04:33 by dongyoki          #+#    #+#             */
/*   Updated: 2022/11/12 14:49:11 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	set_number(const char *str, int flag, size_t i);

int	ft_atoi(const char *str)
{
	size_t			i;
	int				flag;
	long long int	res;

	flag = 1;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = set_number(str, flag, i);
	return ((int)(res * flag));
}

static long long int	set_number(const char *str, int flag, size_t i)
{
	long long int	res;
	long long int	tmp;

	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		tmp = res;
		res *= 10;
		res += (str[i] - '0');
		if (tmp > res)
		{
			if (flag == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (res);
}
