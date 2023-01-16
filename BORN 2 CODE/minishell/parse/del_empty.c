/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:32:43 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/06 15:53:22 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	del_empty(t_parse **lst)
{
	t_parse	*cur;
	t_parse	*pre;

	cur = *lst;
	pre = 0;
	while (cur)
	{
		if (cur->type == DEFA && cur->s[0] == 0)
			del_parse(lst, &cur, &pre);
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}

void	del_parse(t_parse **lst, t_parse **cur, t_parse **pre)
{
	if (!(*pre) && (*cur))
	{
		*lst = (*cur)->next;
		delone_parse((*cur));
		(*cur) = *lst;
	}
	else if ((*pre) && (*cur))
	{
		(*pre)->next = (*cur)->next;
		delone_parse((*cur));
		(*cur) = (*pre)->next;
	}
}
