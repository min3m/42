/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_error_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:35:45 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:14 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

t_cmd	*make_error_cmd(t_parse *cur)
{
	t_cmd	*cmd;

	cmd = new_cmd();
	if (!cmd)
		return (0);
	cmd->arg = malloc(sizeof(char *) * 2);
	cmd->red = malloc(sizeof(t_red));
	cmd->red->file = 0;
	cmd->red->red = 0;
	cmd->arg[0] = cur->s;
	cmd->arg[1] = 0;
	cmd->state = DENY;
	cmd->num = 0;
	return (cmd);
}
