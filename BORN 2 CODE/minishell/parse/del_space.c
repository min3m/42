/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:32:43 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/06 16:07:49 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	del_space(t_parse **lst)
{
	t_parse	*cur;
	t_parse	*pre;

	cur = *lst;
	pre = 0;
	while (cur)
	{
		if (cur->type == SPCE)
			del_parse(lst, &cur, &pre);
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}
