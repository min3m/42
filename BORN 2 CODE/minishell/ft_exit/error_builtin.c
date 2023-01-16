/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:47:03 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 15:09:03 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	error_builtin_exit(char *cmd, char *arg, char *msg)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	if (g_minishell.last_state == 1)
		return (g_minishell.last_state);
	else
		exit(g_minishell.last_state);
}

int	error_builtin_env(char *cmd, char *arg, char *msg)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (127);
}

int	error_builtin_cd(char *cmd, char *arg, char *msg)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}
