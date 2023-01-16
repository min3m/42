/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:35:45 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/11 14:04:56 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

t_cmd	*make_cmd(t_parse *cur, int i)
{
	t_cmd	*cmd;
	int		arg;
	int		red;

	arg = 0;
	red = 0;
	count_arg_red(cur, &red, &arg);
	cmd = new_cmd();
	if (!cmd)
		return (0);
	cmd->arg = malloc(sizeof(char *) * (arg + 1));
	cmd->red = malloc(sizeof(t_red) * (red + 1));
	if (check_cmd_args(cmd))
		return (0);
	red = 0;
	arg = 0;
	while (cur && cur->type != PIPE)
		set_cmd(cmd, &cur, &red, &arg);
	init_cmd(cmd, red, arg);
	set_red(cmd);
	cmd->num = ++i;
	if (set_limit(cmd))
		return (0);
	return (cmd);
}

void	init_cmd(t_cmd *cmd, int red, int arg)
{
	cmd->red[red].file = 0;
	cmd->red[red].red = 0;
	cmd->arg[arg] = 0;
	cmd->state = ALLO;
}

void	count_arg_red(t_parse *cur, int *red, int *arg)
{
	while (cur && cur->type != PIPE && cur->type != ERRO)
	{
		if (cur->type == REDD)
			(*red)++;
		if (cur->type == ABLE)
			(*arg)++;
		cur = cur->next;
	}
	*arg = *arg - *red;
}

int	check_cmd_args(t_cmd *cmd)
{
	if (!cmd->arg || !cmd->red)
	{
		if (cmd->arg)
			free(cmd->arg);
		if (cmd->red)
			free(cmd->red);
		free(cmd);
		return (1);
	}
	return (0);
}
