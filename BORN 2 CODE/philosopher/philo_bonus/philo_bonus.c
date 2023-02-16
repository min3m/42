/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/16 21:56:20 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philo)
{
	sem_close(philo->arg->forks);
	sem_close(philo->arg->print);
	sem_close(philo->arg->count);
	sem_close(philo->arg->last_time);
	sem_close(philo->arg->check_died);
	free(philo);
}

void	wait_process(t_philo *philo, t_arg *arg)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < philo->arg->philo_num)
	{
		waitpid(-1, &wstatus, 0);
		if ((wstatus >> 8 & 0xff) == FULL)
		{
			if (i == philo->arg->philo_num - 1)
				printf("[%llums] eating finished!\n",
					get_ms_time() - arg->start_time);
		}
		else if ((wstatus >> 8 & 0xff) >= 0)
		{
			i = -1;
			while (++i < philo->arg->philo_num)
				kill(philo[i].pid, SIGTERM);
			break ;
		}
	}
	free_all(philo);
}

void	philo_problem(t_philo *philo)
{
	if ((philo->philo_id % 2))
		timer(100);
	while (1)
	{
		eating(philo);
		sem_wait(philo->arg->count);
		if (philo->arg->min_eat_times != 0 &&
			philo->eat_times == philo->arg->min_eat_times)
		{
			sem_post(philo->arg->count);
			sem_post(philo->arg->forks);
			sem_post(philo->arg->forks);
			exit(FULL);
		}
		sem_post(philo->arg->count);
		sleep_think(philo);
	}
}

void	start_process(t_philo *philo, t_arg *arg)
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
			philo_problem(&(philo[i]));
			pthread_join(philo->tid, NULL);
		}
	}
	wait_process(philo, arg);
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
