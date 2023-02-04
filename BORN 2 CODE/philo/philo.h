/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:10:14 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/04 16:17:07 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <memory.h>

/* libft.c */

static int	ft_isspace(const char *nptr, int i);
static bool	ft_atoi(const char *nptr, int *num);
static int	ft_putendl_fd(char *s, int fd);
static int	ft_isdigit(int c);

typedef struct s_arg
{
	int	philo_num;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	min_eat_times;
}				t_arg;

#endif
