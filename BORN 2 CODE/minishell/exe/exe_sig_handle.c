/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_sig_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:13:02 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 20:33:03 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	exe_ctl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	ft_putstr_fd("  \b\b\n", STDERR_FILENO);
	exit(0);
}
