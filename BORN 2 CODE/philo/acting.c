/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:09 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/09 21:51:57 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(char *message, t_philo *philo)
{
	uint64_t	now;

	pthread_mutex_lock(&(philo->arg.print));
	now = get_ms_time();
	printf("[%llums] %d %s\n", now - philo->arg.start_time,
		philo->philo_id, message);
	pthread_mutex_unlock(&(philo->arg.print));
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg.forks[philo->right_f]));
	print_philo("has taken fork", philo);
	pthread_mutex_lock(&(philo->arg.forks[philo->left_f]));
	print_philo("has taken fork", philo);
	print_philo("is eating", philo);
	usleep(philo->arg.t_to_eat);
	philo->last_eat_time = get_ms_time();
	philo->eat_times++;
	pthread_mutex_unlock(&(philo->arg.forks[philo->right_f]));
	pthread_mutex_unlock(&(philo->arg.forks[philo->left_f]));
}

void	sleep_think(t_philo *philo)
{
	print_philo("is sleeping", philo);
	usleep(philo->arg.t_to_sleep);
	print_philo("is thinking", philo);
}
