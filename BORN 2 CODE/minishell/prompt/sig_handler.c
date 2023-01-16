/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/01/03 19:02:30 by marvin            #+#    #+#             */
/*   Updated: 2023/01/03 19:02:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	handle_ctrl_c_h(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", g_minishell.bp_stdout);
}

void	handle_ctrl_c_f(int signum)
{
	(void)signum;
	ft_putchar_fd('\n', g_minishell.bp_stdout);
	g_minishell.last_state = 130;
}

void	sig_exit(int signum)
{
	if (signum == SIGINT)
		exit(1);
}

void	handle_ctrl_d(int errocode)
{
	ft_putendl_fd("exit", 2);
	exit(errocode);
}

void	handle_ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	ft_putstr_fd(ft_strjoin(rl_prompt, rl_line_buffer), g_minishell.bp_stdout);
	ft_putstr_fd("  \b\b", g_minishell.bp_stdout);
	if (rl_on_new_line() == -1)
		exit(EXIT_FAILURE);
	ft_putstr_fd("\n", g_minishell.bp_stdout);
	rl_redisplay();
	rl_replace_line("", 1);
}
