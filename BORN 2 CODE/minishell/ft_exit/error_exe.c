/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:59:50 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/11 20:45:10 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	error_strerror(t_parse **lst, t_cmd **cmd)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	clear_cmd(cmd);
	clear_parse(lst);
	exit(errno);
}

int	error_file(char *file, t_parse **lst, t_cmd **cmd)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	clear_cmd(cmd);
	clear_parse(lst);
	g_minishell.last_state = 1;
	return (g_minishell.last_state);
}

void	error_child(t_parse **lst, t_cmd **cmd)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": child process terminated abnormally", STDERR_FILENO);
	clear_cmd(cmd);
	clear_parse(lst);
	exit(1);
}

void	error_invalid_cmd(char *command, t_parse **lst, t_cmd **cmd)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	clear_cmd(cmd);
	clear_parse(lst);
	exit(127);
}

int	error_token(char *token, t_parse **lst, t_cmd **cmd)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putstr_fd(": syntax error near unexpected token '", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	clear_cmd(cmd);
	clear_parse(lst);
	g_minishell.last_state = 258;
	return (g_minishell.last_state);
}
