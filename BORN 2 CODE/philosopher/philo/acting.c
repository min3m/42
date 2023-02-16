/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:09 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/14 20:05:46 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer(int time)
{
	uint64_t	target_time;

	target_time = get_ms_time() + (uint64_t)time;
	while (target_time > get_ms_time())
		usleep(200);
}

void	print_philo(char *message, t_philo *philo)
{
	uint64_t	now;

	pthread_mutex_lock(&(philo->arg->check_died));
	now = get_ms_time();
	if (!(philo->arg->died))
	{
		pthread_mutex_lock(&(philo->arg->print));
		printf("[%llums] %d %s\n", now - philo->arg->start_time,
			philo->philo_id, message);
		pthread_mutex_unlock(&(philo->arg->print));
	}
	pthread_mutex_unlock(&(philo->arg->check_died));
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg->forks[philo->right_f]));
	print_philo("has taken fork", philo);
	pthread_mutex_lock(&(philo->arg->forks[philo->left_f]));
	print_philo("has taken fork", philo);
	print_philo("is eating", philo);
	timer(philo->arg->t_to_eat);
	pthread_mutex_lock(&(philo->arg->last_time));
	philo->last_eat_time = get_ms_time();
	pthread_mutex_unlock(&(philo->arg->last_time));
	pthread_mutex_lock(&(philo->arg->count));
	philo->eat_times++;
	pthread_mutex_unlock(&(philo->arg->count));
	pthread_mutex_unlock(&(philo->arg->forks[philo->right_f]));
	pthread_mutex_unlock(&(philo->arg->forks[philo->left_f]));
	sleep_think(philo);
}

void	sleep_think(t_philo *philo)
{
	print_philo("is sleeping", philo);
	timer(philo->arg->t_to_sleep);
	print_philo("is thinking", philo);
}
