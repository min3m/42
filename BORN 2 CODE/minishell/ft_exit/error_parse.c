/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:59:50 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 12:58:23 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	error_nothing(void)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": memory allocation failed", STDERR_FILENO);
	exit(1);
}

void	error_parse(t_parse **lst)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": memory allocation failed", STDERR_FILENO);
	clear_parse(lst);
	exit(1);
}
