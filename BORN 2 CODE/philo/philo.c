/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/02/04 16:17:34 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("Require 5 or 6 argument!", 1));
	memset(&arg, 0, sizeof(arg));
	if (!init_arg(&arg, argv))
		return (ft_putendl_fd("Wrong argument!", 1));
	return (0);
}
