/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/09 21:48:06 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < philo->arg.philo_num)
		pthread_mutex_destroy(&(philo->arg.forks[i]));
	pthread_mutex_destroy(&(philo->arg.count));
	pthread_mutex_destroy(&(philo->arg.print));
	free(philo->arg.forks);
	free(philo);
}

void	philo_monitor(t_philo *philo)
{
	uint64_t	now;
	int			i;

	i = -1;
	now = get_ms_time();
	while (1)
	{
		if (philo->arg.finished == philo->arg.philo_num)
		{
			printf("eating finished!\n");
			return ;
		}
		while (++i < philo->arg.philo_num)
		{
			if (now - philo->last_eat_time >= (uint64_t)philo->arg.t_to_die)
			{
				printf("%d died\n", philo[i].philo_id);
				return ;
			}
		}
	}
}

void	*philo_problem(void *val)
{
	t_philo		*philo_info;
	t_arg		*temp;

	philo_info = (t_philo *)val;
	if (!(philo_info->philo_id % 2))
		usleep(100);
	while (!(philo_info->died))
	{
		eating(philo_info);
		if (philo_info->eat_times == philo_info->arg.min_eat_times)
		{
			pthread_mutex_lock(&(philo_info->arg.count));
			temp = &(philo_info->arg);
			(*temp).finished++;
			pthread_mutex_unlock(&(philo_info->arg.count));
			break ;
		}
		sleep_think(philo_info);
	}
	return (NULL);
}

void	start_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->arg.philo_num)
	{
		philo[i].last_eat_time = get_ms_time();
		if (pthread_create(&(philo[i].tid), NULL, philo_problem, &(philo[i])))
			exit(ft_putendl_fd("Thread create Error!", 1));
	}
	philo_monitor(philo);
	i = -1;
	while (++i < philo->arg.philo_num)
	{
		if (pthread_detach(philo[i].tid))
			exit(ft_putendl_fd("Thread free Error!", 1));
	}
	free_all(philo);
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
	if (!init_philo(&philo, arg))
		return (ft_putendl_fd("Thread init error!", 1));
	start_thread(philo);
	return (0);
}
