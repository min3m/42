/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:10:14 by youngmch          #+#    #+#             */
/*                                                                            */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <memory.h>
# include <limits.h>

/* libft.c */

static int	ft_isspace(const char *nptr, int i);
static bool	matoi(const char *nptr, int *num);
static int	ft_putendl_fd(char *s, int fd);
static int	ft_isdigit(int c);

typedef struct s_arg
{
	int				philo_num;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				min_eat_times;
	pthread_mutex_t	*forks;
}				t_arg;

typedef struct s_philo
{
	t_arg		arg;
	pthread_t	tid;
	int			philo_id;
	int			right_f;
	int			left_f;
}				t_philo;


#endif
