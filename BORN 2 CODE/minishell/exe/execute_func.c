/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:19:45 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/16 16:38:22 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	check_exit(t_parse **lst, t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur->next)
		cur = cur->next;
	if (cur && cur->num == 1 && cur->arg && cur->arg[0] && ft_strcmp("exit",
			cur->arg[0]) == 0 && cur->arg[1] && !ft_atoll(cur->arg[1])
		&& cur->arg[2])
		child_main(lst, cmd, 1);
	if (cur && cur->num == 1 && cur->arg && cur->arg[0] && is_builtin_bool(cur))
	{
		g_minishell.last_state = is_builtin(cur);
		close_all_pipe(cmd);
		clear_cmd(cmd);
		clear_parse(lst);
		return (1);
	}
	return (0);
}

int	init_exe(t_parse **lst, t_cmd **cmd, char *s)
{
	*lst = parse_main(s);
	*cmd = initcmd(lst);
	if (!(*cmd))
		return (g_minishell.last_state);
	signal(SIGINT, handle_ctrl_c_h);
	g_minishell.last_state = here_doc_fork(lst, cmd);
	if (g_minishell.last_state)
		return (g_minishell.last_state);
	open_heredoc(lst, cmd);
	if (if_deny(lst, cmd))
		return (g_minishell.last_state);
	return (0);
}

int	here_doc_fork(t_parse **lst, t_cmd **cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == -1)
		error_strerror(lst, cmd);
	else if (pid == 0)
	{
		signal(SIGINT, sig_exit);
		make_heredoc(lst, cmd);
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WTERMSIG(status));
}

int	end_exe(t_parse **lst, t_cmd **cmd)
{
	close_all_pipe(cmd);
	g_minishell.last_state = wait_every_pid(lst, cmd);
	clear_cmd(cmd);
	clear_parse(lst);
	return (g_minishell.last_state);
}
