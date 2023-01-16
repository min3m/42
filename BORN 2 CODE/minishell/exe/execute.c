/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:15:23 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/16 16:32:11 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	execute(char *s)
{
	t_cmd	*cmd;
	t_parse	*lst;
	t_cmd	*cur;
	int		i;

	// signal(SIGINT, SIG_IGN);
	if (init_exe(&lst, &cmd, s))
		return (g_minishell.last_state);
	if (check_exit(&lst, &cmd))
		return (g_minishell.last_state);
	signal(SIGQUIT, handle_ctrl_back);
	cur = cmd;
	i = 1;
	while (cur)
	{
		execute_fork(&lst, &cmd, i);
		cur = cur->next;
		i++;
	}
	return (end_exe(&lst, &cmd));
}

void	execute_fork(t_parse **lst, t_cmd **cmd, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_strerror(lst, cmd);
	else if (pid == 0)
	{
		signal(SIGINT, sig_exit);
		signal(SIGQUIT, handle_ctrl_back_f);
		child_main(lst, cmd, i);
	}
	else
		parent_main(cmd, pid, i);
}

int	wait_every_pid(t_parse **lst, t_cmd **cmd)
{
	t_cmd	*cur;
	pid_t	child;
	int		status;

	cur = *cmd;
	while (cur)
	{
		child = waitpid(cur->pid, &status, 0);
		if (child == -1 && errno != ECHILD)
			error_child(lst, cmd);
		cur = cur->next;
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WTERMSIG(status));
}

int	if_deny(t_parse **lst, t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->state == DENY)
			return (error_token(cur->arg[0], lst, cmd));
		cur = cur->next;
	}
	return (0);
}
