/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:47:26 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/18 20:35:53 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_die(t_philo *philo, t_arg *arg)
{
	uint64_t	now;
	uint64_t	died_time;

	sem_wait(philo->arg->last_time);
	now = get_ms_time();
	died_time = now - philo->last_eat_time;
	sem_post(philo->arg->last_time);
	if (died_time >= (uint64_t)arg->t_to_die)
	{
		sem_wait(philo->arg->print);
		printf("[%llums] %d died\n", now - philo->arg->start_time,
			philo->philo_id);
		return (1);
	}
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
		if (check_die(philo, arg))
			exit(DIED);
		sem_wait(philo->arg->count);
		if (philo->arg->min_eat_times != 0 &&
			philo->eat_times == philo->arg->min_eat_times)
		{
			sem_post(philo->arg->forks);
			sem_post(philo->arg->forks);
			exit(FULL);
		}
		sem_post(philo->arg->count);
	}
	return (NULL);
}
