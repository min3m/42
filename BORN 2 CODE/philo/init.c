/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:57 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/07 16:09:05 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_philo(t_philo **philo, t_arg arg)
{
	*philo = malloc(sizeof(t_philo) * arg.philo_num);
	if (!(*philo))
		return (false);
	return (true);
}

static bool	init_mutex(t_arg *arg)
{
	int	i;

	i = -1;
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->philo_num);
	if (!arg->forks)
		return (false);
	while (++i < arg->philo_num)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (false);
	}
	return (true);
}

static bool	init_arg(t_arg *arg, char **argv)
{
	if (!matoi(argv[1], arg->philo_num) || !matoi(argv[2], arg->t_to_die)
		|| !matoi(argv[3], arg->t_to_eat) || !matoi(argv[4], arg->t_to_sleep))
		return (false);
	if (arg->philo_num < 1 || arg->t_to_die <= 0 || arg->t_to_eat <= 0
		|| arg->t_to_sleep <= 0)
		return (false);
	if (argv[5])
	{
		if (!matoi(argv[5], arg->min_eat_times))
			return (false);
		if (arg->min_eat_times <= 0)
			return (false);
	}
	return (true);
}
