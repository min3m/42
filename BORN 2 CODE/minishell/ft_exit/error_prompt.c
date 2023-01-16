/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:51:21 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 15:09:50 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	error_prompt_line(char *line)
{
	ft_free(line);
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": memory allocation failed", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	error_env(t_env **lst, t_env *new)
{
	if (new)
		delone_env(new);
	clear_env(lst);
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": memory allocation failed", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	error_init(void)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": memory allocation failed", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
