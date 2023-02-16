/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:47:26 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/14 20:52:56 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_philo *philo, t_arg *arg)
{
	uint64_t	now;
	uint64_t	died_time;
	int			i;

	i = -1;
	while (++i < arg->philo_num)
	{
		pthread_mutex_lock(&(philo[i].arg->last_time));
		now = get_ms_time();
		died_time = now - philo[i].last_eat_time;
		pthread_mutex_unlock(&(philo[i].arg->last_time));
		if (died_time >= (uint64_t)arg->t_to_die)
		{
			print_philo("died", &(philo[i]));
			pthread_mutex_lock(&(arg->check_died));
			philo[i].arg->died = true;
			pthread_mutex_unlock(&(arg->check_died));
			return (1);
		}
	}
	return (0);
}

int	check_min_eat(t_arg *arg)
{
	uint64_t	now;

	pthread_mutex_lock(&(arg->count));
	if (arg->min_eat_times != 0 && arg->finished == arg->philo_num)
	{
		pthread_mutex_unlock(&(arg->count));
		now = get_ms_time();
		printf("[%llums] eating finished!\n", now - arg->start_time);
		pthread_mutex_lock(&(arg->check_died));
		arg->died = true;
		pthread_mutex_unlock(&(arg->check_died));
		return (1);
	}
	pthread_mutex_unlock(&(arg->count));
	return (0);
}

void	philo_monitor(t_philo *philo, t_arg *arg)
{
	while (1)
	{
		if (check_min_eat(arg))
			return ;
		if (check_die(philo, arg))
			return ;
	}
}
