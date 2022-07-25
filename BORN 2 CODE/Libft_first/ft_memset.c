/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:24:17 by youngmch          #+#    #+#             */
/*   Updated: 2022/07/19 13:22:13 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t num)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)str;
	i = 0;
	while (i < num)
	{
		temp[i] = (unsigned char)value;
		i++;
	}
	return (temp);
}
