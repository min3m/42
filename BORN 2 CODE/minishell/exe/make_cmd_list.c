/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:06:20 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/11 14:10:09 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

t_cmd	*make_cmd_list(t_parse **lst)
{
	t_parse	*cur;
	t_cmd	*cmd;
	t_cmd	*new;
	int		i;

	i = 1;
	cur = *lst;
	cmd = 0;
	if (cur->type == ERRO)
		new = make_error_cmd(cur);
	else
		new = make_cmd(cur, 0);
	if (!new)
		error_parse(lst);
	add_cmd(&cmd, new);
	while (cur)
		make_cmd_loop(lst, &cur, &cmd, &i);
	return (cmd);
}

void	make_cmd_loop(t_parse **lst, t_parse **cur, t_cmd **cmd, int *i)
{
	t_cmd	*new;

	if ((*cur)->type == PIPE)
	{
		new = make_cmd((*cur)->next, (*i)++);
		if (!new)
			error_cmd(lst, cmd);
		add_cmd(cmd, new);
	}
	if ((*cur)->type == ERRO)
	{
		new = make_error_cmd((*cur));
		if (!new)
			error_cmd(lst, cmd);
		add_cmd(cmd, new);
	}
	(*cur) = (*cur)->next;
}
