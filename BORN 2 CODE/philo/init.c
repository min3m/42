/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:57 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/04 16:24:18 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_arg(t_arg *arg, char **argv)
{
	if (!ft_atoi(argv[1], arg->philo_num) || !ft_atoi(argv[2], arg->t_to_die)
	|| !ft_atoi(argv[3], arg->t_to_eat) || !ft_atoi(argv[4], arg->t_to_sleep))
		return (false);
	if (argv[5])
	{
		if (atoi)
	}
	return (true);
}
