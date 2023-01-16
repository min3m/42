/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_able.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:06 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/06 15:57:15 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	change_able(t_parse **lst)
{
	t_parse	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->type == DEFA)
			cur->type = ABLE;
		cur = cur->next;
	}
}
