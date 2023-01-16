/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:00:09 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/12 14:04:56 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	handle_ctrl_back(int signum)
{
	if (signum == SIGQUIT)
		ft_putendl_fd("Quit: 3", STDERR_FILENO);
}

void	handle_ctrl_back_f(int signum)
{
	if (signum == SIGQUIT)
		exit(1);
}
