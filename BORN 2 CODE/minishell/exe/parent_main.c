/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:04:05 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 12:54:20 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	parent_main(t_cmd **cmd, pid_t pid, int i)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->num == i)
			cur->pid = pid;
		cur = cur->next;
	}
}
