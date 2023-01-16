/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:04:05 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 10:32:50 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	child_main(t_parse **lst, t_cmd **cmd, int i)
{
	t_cmd	*cur;
	t_cmd	*pre;

	cur = find_cmd(cmd, i);
	pre = find_pre(cmd, i);
	if (set_redirection(cur, pre))
		error_strerror(lst, cmd);
	close_all_pipe(cmd);
	exec_cmd(lst, cmd, cur);
}

t_cmd	*find_cmd(t_cmd **cmd, int i)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->num == i)
			return (cur);
		cur = cur->next;
	}
	return (0);
}

t_cmd	*find_pre(t_cmd **cmd, int i)
{
	t_cmd	*cur;
	t_cmd	*pre;

	cur = *cmd;
	pre = 0;
	while (cur)
	{
		if (cur->num == i)
			return (pre);
		pre = cur;
		cur = cur->next;
	}
	return (0);
}

void	close_all_pipe(t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		close(cur->fd[0]);
		close(cur->fd[1]);
		if (cur->rein)
			close(cur->infd);
		if (cur->reou)
			close(cur->oufd);
		cur = cur->next;
	}
}

int	set_redirection(t_cmd *cur, t_cmd *pre)
{
	if (pre)
	{
		if (dup2(pre->fd[0], STDIN_FILENO) == -1)
			return (1);
	}
	if (cur->next)
	{
		if (dup2(cur->fd[1], STDOUT_FILENO) == -1)
			return (1);
	}
	if (cur->rein)
	{
		if (dup2(cur->infd, STDIN_FILENO) == -1)
			return (1);
	}
	if (cur->reou)
	{
		if (dup2(cur->oufd, STDOUT_FILENO) == -1)
			return (1);
	}
	return (0);
}
