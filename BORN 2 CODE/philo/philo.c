/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:09:24 by youngmch          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/26 18:33:08 by youngmch         ###   ########.fr       */
=======
/*   Updated: 2023/02/01 20:29:34 by youngmin         ###   ########.fr       */
>>>>>>> 2f26948f2e4bc64a18858864aa652ffb204e0a25
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
<<<<<<< HEAD
		return (ft_putendl_fd("Require 5 or 6 argument!"));
=======
		return(ft_putendl_fd("Require 5 or 6 argument!"));
	memset(&arg, 0, sizeof(arg));
	if (init_arg(&arg, argv))
>>>>>>> 2f26948f2e4bc64a18858864aa652ffb204e0a25
	return (0);
}
