/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:17:36 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/27 16:22:41 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_check_arg(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		if (!(ft_isinteger(arr[i])))
		{
			free_arr(arr);
			exit(ft_putendl_fd("Error", 1));
		}
		while (arr[j])
		{
			if (!(ft_strcmp(arr[i], arr[j])))
			{
				free_arr(arr);
				exit(ft_putendl_fd("Error", 1));
			}
			j++;
		}
		i++;
	}
}
