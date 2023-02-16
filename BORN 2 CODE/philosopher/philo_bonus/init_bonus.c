/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:57 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/15 20:20:30 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		(*philo)[i].last_eat_time = 0;
		(*philo)[i].eat_times = 0;
	}
	return (true);
}

bool	init_sem(t_arg *arg)
{
	sem_unlink("forks");
	arg->forks = sem_open("forks", O_CREAT, 0644, arg->philo_num);
	if (arg->forks == SEM_FAILED)
		return (false);
	sem_unlink("print");
	arg->print = sem_open("print", O_CREAT, 0644, 1);
	if (arg->print == SEM_FAILED)
		return (false);
	sem_unlink("count");
	arg->count = sem_open("count", O_CREAT, 0644, 1);
	if (arg->count == SEM_FAILED)
		return (false);
	sem_unlink("last_time");
	arg->last_time = sem_open("last_time", O_CREAT, 0644, 1);
	if (arg->last_time == SEM_FAILED)
		return (false);
	sem_unlink("check_died");
	arg->check_died = sem_open("check_died", O_CREAT, 0644, 1);
	if (arg->check_died == SEM_FAILED)
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
