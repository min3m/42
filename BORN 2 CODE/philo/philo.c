/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/08 20:34:12 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_problem(void *val)
{
	t_philo	*philo_info;

	philo_info = (t_philo *)val;
	if (philo_info->philo_id % 2)
		usleep(100);
	while (!(philo_info->died))
	{
		eating(philo_info);
		if ()
	}
}

void	start_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->arg.philo_num)
	{
		if (pthread_create(&(philo->tid), NULL, philo_problem, &(philo[i])))
			exit(ft_putendl_fd("Thread create Error!", 1));
	}
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
	if (!init_mutex(&arg, argv))
		return (ft_putendl_fd("Mutex init error!", 1));
	if (!init_philo(&philo, arg))
		return (ft_putendl_fd("Thread init error!", 1));
	start_thread(philo);
	return (0);
}
