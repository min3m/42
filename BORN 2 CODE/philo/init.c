/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:57 by youngmin          #+#    #+#             */
/*   Updated: 2023/02/04 16:29:04 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_arg(t_arg *arg, char **argv)
{
	if (!matoi(argv[1], &(arg->philo_num)) || !matoi(argv[2], &(arg->t_to_die))
	 || !matoi(argv[3], arg->t_to_eat) || !matoi(argv[4], arg->t_to_sleep))
		return (false);
}
