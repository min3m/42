/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:59:17 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/12 16:35:38 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_line(char **line_split)
{
	int	count;

	count = 0;
	while (line_split[count])
		count++;
	return (count);
}

int	get_addnum(int num)
{
	if (num < 0)
		return (-1);
	else
		return (1);
}

float	get_radian(int degree)
{
	float	pi;

	pi = 3.141592;
	return ((float)degree * pi / 180);
}
