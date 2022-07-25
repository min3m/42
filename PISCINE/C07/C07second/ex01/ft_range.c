/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:44:15 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/06 13:46:50 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	i = 0;
	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * (max - min));
	if (!(range))
		return (0);
	while (max > min)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
