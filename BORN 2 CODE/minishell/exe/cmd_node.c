/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:56:18 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:22 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	add_cmd(t_cmd **lst, t_cmd *cmd)
{
	t_cmd	*last;

	last = last_cmd(*lst);
	if (!last)
		*lst = cmd;
	else
		last->next = cmd;
}

void	clear_cmd(t_cmd **lst)
{
	t_cmd	*cur;

	if (!(*lst))
		return ;
	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		delone_cmd(cur);
	}
}

void	delone_cmd(t_cmd *lst)
{
	if (lst->arg)
		free(lst->arg);
	if (lst->red)
		free(lst->red);
	if (lst->limi)
		free(lst->infi);
	free(lst);
}

t_cmd	*last_cmd(t_cmd *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	if (!res)
		return (0);
	res->num = 0;
	res->pid = 0;
	res->arg = 0;
	res->red = 0;
	res->state = 0;
	res->rein = 0;
	res->limi = 0;
	res->infi = 0;
	res->reou = 0;
	res->oufi = 0;
	res->fd[0] = 0;
	res->fd[1] = 0;
	res->infd = 0;
	res->oufd = 0;
	res->next = 0;
	return (res);
}
