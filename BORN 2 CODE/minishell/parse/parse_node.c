/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:56:18 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	add_parse(t_parse **lst, char *s, int type, int quote)
{
	t_parse	*last;
	t_parse	*res;

	res = new_parse(s, type, quote);
	if (!res)
		return (1);
	last = last_parse(*lst);
	if (!last)
		*lst = res;
	else
		last->next = res;
	return (0);
}

void	clear_parse(t_parse **lst)
{
	t_parse	*cur;

	if (!(*lst))
		return ;
	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		delone_parse(cur);
	}
}

void	delone_parse(t_parse *lst)
{
	if (lst->s)
		free(lst->s);
	free(lst);
}

t_parse	*last_parse(t_parse *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_parse	*new_parse(char *s, int type, int quote)
{
	t_parse	*res;

	res = malloc(sizeof(t_parse));
	if (!res)
		return (0);
	res->s = s;
	res->next = 0;
	res->type = type;
	res->in_quote = quote;
	return (res);
}
