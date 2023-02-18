/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/18 21:37:52 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < philo->arg->philo_num)
		pthread_mutex_destroy(&(philo->arg->forks[i]));
	pthread_mutex_destroy(&(philo->arg->count));
	pthread_mutex_destroy(&(philo->arg->print));
	pthread_mutex_destroy(&(philo->arg->last_time));
	pthread_mutex_destroy(&(philo->arg->check_died));
	free(philo->arg->forks);
	free(philo);
}

void	*philo_problem(void *val)
{
	t_philo		*philo_info;

	philo_info = (t_philo *)val;
	if ((philo_info->philo_id % 2))
		timer(100);
	while (1)
	{
		pthread_mutex_lock(&(philo_info->arg->check_died));
		if (philo_info->arg->died)
		{
			pthread_mutex_unlock(&(philo_info->arg->check_died));
			break ;
		}
		pthread_mutex_unlock(&(philo_info->arg->check_died));
		if (eating(philo_info))
			break ;
		sleep_think(philo_info);
	}
	return (NULL);
}

int	start_thread(t_philo *philo, t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < philo->arg->philo_num)
	{
		philo[i].last_eat_time = get_ms_time();
		if (pthread_create(&(philo[i].tid), NULL, philo_problem, &(philo[i])))
			return (ft_putendl_fd("Thread create Error!", 1));
	}
	philo_monitor(philo, arg);
	i = -1;
	if (philo->arg->philo_num == 1)
	{
		if (pthread_detach(philo[0].tid))
			return (ft_putendl_fd("Thread free Error!", 1));
	}
	else
	{
		while (++i < philo->arg->philo_num)
			if (pthread_join(philo[i].tid, NULL))
				return (ft_putendl_fd("Thread free Error!", 1));
	}
	free_all(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("Require 5 or 6 argument!", 1));
	memset(&arg, 0, sizeof(t_arg));
	if (!init_arg(&arg, argv))
		return (ft_putendl_fd("Wrong argument!", 1));
	if (!init_mutex(&arg))
		return (ft_putendl_fd("Mutex init error!", 1));
	if (!init_philo(&philo, &arg))
		return (ft_putendl_fd("Thread init error!", 1));
	start_thread(philo, &arg);
	return (0);
}
