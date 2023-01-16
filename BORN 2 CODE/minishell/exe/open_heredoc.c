/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:39:26 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/09 16:40:33 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	open_heredoc(t_parse **lst, t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->rein)
		{
			if (cur->rein[1] == '<')
			{
				cur->infd = open(cur->infi, O_RDONLY);
				if (cur->infd < 0)
					error_file(cur->infi, lst, cmd);
			}
		}
		cur = cur->next;
	}
}
