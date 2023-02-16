/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/15 22:30:38 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philo)
{
	int		i;

	i = -1;
	free(philo);
}

void	philo_problem(t_philo *philo, t_arg *arg)
{
	if ((philo->philo_id % 2))
		timer(100);
	while (1)
	{
		eating(philo_info);
	}
	return (NULL);
}

int	start_process(t_philo *philo, t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < philo->arg->philo_num)
	{
		philo[i].pid = fork();
		philo[i].last_eat_time = get_ms_time();
		if (philo[i].pid < 0)
			exit (ft_putendl_fd("Fork error!", 1));
		if (philo[i].pid == 0)
		{
			if (pthread_create(&(philo->tid), NULL, philo_monitor, &(philo[i])))
				exit(ft_putendl_fd("Thread create error!", 1));
			philo_problem(&(philo[i]), arg);
		}
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
	if (!init_sem(&arg))
		return (ft_putendl_fd("Mutex init error!", 1));
	if (!init_philo(&philo, &arg))
		return (ft_putendl_fd("Thread init error!", 1));
	start_process(philo, &arg);
	return (0);
}
