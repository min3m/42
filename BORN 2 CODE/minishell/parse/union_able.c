/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_able.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:58:34 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	union_able(t_parse **lst)
{
	t_parse	*cur;
	t_parse	*pre;
	t_parse	*tmp;
	int		type;
	char	*s;

	cur = *lst;
	pre = 0;
	type = 0;
	while (cur)
	{
		if (type == 0 && cur->type == ABLE)
			type = set_first_parse(&tmp, &cur, &pre, &s);
		else if (cur->type == ABLE)
			join_able(lst, &tmp, &cur, &pre);
		else
		{
			type = 0;
			pre = cur;
			cur = cur->next;
		}
	}
}

int	set_first_parse(t_parse **tmp, t_parse **cur, t_parse **pre, char **s)
{
	*tmp = *cur;
	*s = (*cur)->s;
	*pre = *cur;
	*cur = (*cur)->next;
	return (ABLE);
}

void	join_able(t_parse **lst, t_parse **tmp, t_parse **cur, t_parse **pre)
{
	char	*s;

	s = ft_strjoin((*tmp)->s, (*cur)->s);
	if (!s)
		error_parse(lst);
	free((*tmp)->s);
	(*tmp)->s = s;
	del_parse(lst, cur, pre);
}
