/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:47:26 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/15 22:24:58 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_die(t_philo *philo, t_arg *arg)
{
	uint64_t	now;
	uint64_t	died_time;
	int			i;

	i = -1;
	while (++i < arg->philo_num)
	{
		sem_wait(philo[i].arg->last_time);
		now = get_ms_time();
		died_time = now - philo[i].last_eat_time;
		sem_post(philo[i].arg->last_time);
		if (died_time >= (uint64_t)arg->t_to_die)
		{
			print_philo("died", &(philo[i]));
			sem_wait(arg->check_died);
			philo[i].arg->died = true;
			sem_post(arg->check_died);
			return (1);
		}
	}
	return (0);
}

int	check_min_eat(t_arg *arg)
{
	uint64_t	now;

	sem_wait(arg->count);
	if (arg->finished == arg->philo_num)
	{
		sem_post(arg->count);
		now = get_ms_time();
		printf("[%llums] eating finished!\n", now - arg->start_time);
		sem_wait(arg->check_died);
		arg->died = true;
		sem_post(arg->check_died);
		return (1);
	}
	sem_post(arg->count);
	return (0);
}

void	*philo_monitor(void *val)
{
	t_philo	*philo;
	t_arg	*arg;

	philo = (t_philo *)val;
	arg = philo->arg;
	while (1)
	{
		if (arg->min_eat_times != 0 && check_min_eat(arg))
			exit(FULL);
		if (check_die(philo, arg))
			exit(DIED);
	}
}
