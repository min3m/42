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

typedef struct s_arg
{
	int				philo_num;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				min_eat_times;
	int				finished;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	count;
	uint64_t		start_time;
}				t_arg;

typedef struct s_philo
{
	t_arg		arg;
	pthread_t	tid;
	int			philo_id;
	int			right_f;
	int			left_f;
	bool		died;
	int			eat_times;
	uint64_t	last_eat_time;
}				t_philo;

/* libft.c */

int			ft_isspace(const char *nptr, int i);
bool		matoi(const char *nptr, int *num);
int			ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
uint64_t	get_ms_time(void);

/* init.c */

bool		init_arg(t_arg *arg, char **argv);
bool		init_mutex(t_arg *arg);
bool		init_philo(t_philo **philo, t_arg arg);

/* acting.c */

void		print_philo(char *message, t_philo *philo);
void		eating(t_philo *philo);
void		sleep_think(t_philo *philo);

/* philo.c */

void		philo_monitor(t_philo *philo);
void		start_thread(t_philo *philo);
void		*philo_problem(void *val);

#endif
