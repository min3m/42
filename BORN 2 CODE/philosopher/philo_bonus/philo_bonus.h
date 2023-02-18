/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:53:36 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/18 20:33:55 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <memory.h>
# include <semaphore.h>
# include <signal.h>
# include <limits.h>

# define DIED 0xfd
# define FULL 0xfe

typedef struct s_arg
{
	int			philo_num;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			min_eat_times;
	int			finished;
	bool		died;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*count;
	sem_t		*last_time;
	uint64_t	start_time;
}				t_arg;

typedef struct s_philo
{
	t_arg		*arg;
	pid_t		pid;
	pthread_t	tid;
	int			philo_id;
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
bool		init_sem(t_arg *arg);
bool		init_philo(t_philo **philo, t_arg *arg);
bool		init_philo_sem(t_philo **philo, t_arg *arg);

/* acting.c */

void		timer(int time);
void		print_philo(char *message, t_philo *philo);
void		eating(t_philo *philo);
void		sleep_think(t_philo *philo);

/* monitor.c */

void		*philo_monitor(void *val);
int			check_die(t_philo *philo, t_arg *arg);

/* philo.c */

void		free_all(t_philo *philo);
void		wait_process(t_philo *philo, t_arg *arg);
void		philo_problem(t_philo *philo);
void		start_process(t_philo *philo, t_arg *arg);

#endif
