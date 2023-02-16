/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:09 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/16 21:48:31 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	timer(int time)
{
	uint64_t	target_time;

	target_time = get_ms_time() + (uint64_t)time;
	while (target_time > get_ms_time())
		usleep(500);
}

void	print_philo(char *message, t_philo *philo)
{
	uint64_t	now;

	sem_wait(philo->arg->check_died);
	now = get_ms_time();
	if (!(philo->arg->died))
	{
		sem_wait(philo->arg->print);
		printf("[%llums] %d %s\n", now - philo->arg->start_time,
			philo->philo_id, message);
		sem_post(philo->arg->print);
	}
	sem_post(philo->arg->check_died);
}

void	eating(t_philo *philo)
{
	sem_wait(philo->arg->forks);
	print_philo("has taken fork", philo);
	sem_wait(philo->arg->forks);
	print_philo("has taken fork", philo);
	print_philo("is eating", philo);
	timer(philo->arg->t_to_eat);
	sem_wait(philo->arg->last_time);
	philo->last_eat_time = get_ms_time();
	sem_post(philo->arg->last_time);
	sem_wait(philo->arg->count);
	philo->eat_times++;
	sem_post(philo->arg->count);
	sem_post(philo->arg->forks);
	sem_post(philo->arg->forks);
}

void	sleep_think(t_philo *philo)
{
	print_philo("is sleeping", philo);
	timer(philo->arg->t_to_sleep);
	print_philo("is thinking", philo);
}
