/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:57 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/12 23:58:33 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philo(t_philo **philo, t_arg *arg)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * arg->philo_num);
	if (!(*philo))
		return (false);
	while (++i < arg->philo_num)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].arg->died = false;
		(*philo)[i].philo_id = i;
		(*philo)[i].right_f = i;
		(*philo)[i].left_f = (i + 1) % arg->philo_num;
		(*philo)[i].last_eat_time = 0;
		(*philo)[i].eat_times = 0;
	}
	return (true);
}

bool	init_mutex(t_arg *arg)
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
	if (pthread_mutex_init(&(arg->print), NULL))
		return (false);
	if (pthread_mutex_init(&(arg->count), NULL))
		return (false);
	if (pthread_mutex_init(&(arg->last_time), NULL))
		return (false);
	if (pthread_mutex_init(&(arg->check_died), NULL))
		return (false);
	return (true);
}

bool	init_arg(t_arg *arg, char **argv)
{
	if (!matoi(argv[1], &(arg->philo_num)) || !matoi(argv[2], &(arg->t_to_die))
		|| !matoi(argv[3], &(arg->t_to_eat))
		|| !matoi(argv[4], &(arg->t_to_sleep)))
		return (false);
	if (arg->philo_num < 1 || arg->t_to_die <= 0 || arg->t_to_eat <= 0
		|| arg->t_to_sleep <= 0)
		return (false);
	arg->start_time = get_ms_time();
	if (argv[5])
	{
		if (!matoi(argv[5], &(arg->min_eat_times)))
			return (false);
		if (arg->min_eat_times <= 0)
			return (false);
	}
	return (true);
}
