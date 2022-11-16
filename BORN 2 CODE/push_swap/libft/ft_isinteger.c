/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:18:16 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/15 15:37:30 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinteger(char *str)
{
	int	sign;
	size_t	num;

	num = 0;
	sign = 1;
	if (*str == '-' && str++)
		sign = -1;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
				exit(ft_putendl_fd("Error", 1));
		num = 10 * num + (*str - '0');
		str++;
	}
	if (sign > 0 && num > (size_t)INT_MAX)
		return (0);
	else if (sign < 0 && num > (size_t)INT_MAX + 1)
		return (0);
	else
		return (1);
}
