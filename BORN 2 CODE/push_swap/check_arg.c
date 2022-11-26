/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:40 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 16:59:39 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	check_sorted(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i + 1])
		{
			if (ft_atoi(arr[i + 1]) < ft_atoi(arr[i]))
				return ;
		}
		i++;
	}
	free_arr(arr);
	exit(EXIT_SUCCESS);
}

void	check_arg(char **arr)
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
	check_sorted(arr);
}
