/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:34:43 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/04 17:31:39 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi_base(char *nptr)
{
	long long	num;
	int			i;

	i = 0;
	num = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			num = num * 16 + (nptr[i] - '0');
		else if (nptr[i] >= 'A' && nptr[i] <= 'F')
			num = num * 16 + (nptr[i] - 55);
		else if (nptr[i] >= 'a' && nptr[i] <= 'f')
			num = num * 16 + (nptr[i] - 87);
		i++;
	}
	return ((int)num);
}
