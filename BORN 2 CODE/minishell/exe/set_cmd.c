/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:35:45 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:22 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	set_cmd(t_cmd *cmd, t_parse **cur, int *red, int *arg)
{
	if ((*cur)->type == REDD)
	{
		cmd->red[*red].red = (*cur)->s;
		cmd->red[*red].file = (*cur)->next->s;
		(*red)++;
		(*cur) = (*cur)->next;
	}
	else if ((*cur)->type == ABLE)
	{
		cmd->arg[*arg] = (*cur)->s;
		(*arg)++;
	}
	(*cur) = (*cur)->next;
}

void	set_red(t_cmd *cmd)
{
	int	i;
	int	rein;
	int	reou;

	i = 0;
	rein = -1;
	reou = -1;
	while (cmd->red[i].red)
	{
		if (cmd->red[i].red[0] == '<')
			rein = i;
		else if (cmd->red[i].red[0] == '>')
			reou = i;
		i++;
	}
	if (rein != -1)
	{
		cmd->rein = cmd->red[rein].red;
		cmd->infi = cmd->red[rein].file;
	}
	if (reou != -1)
	{
		cmd->reou = cmd->red[reou].red;
		cmd->oufi = cmd->red[reou].file;
	}
}

int	set_limit(t_cmd *cmd)
{
	char	*tmp;

	if (!cmd->rein || (cmd->rein && cmd->rein[1] == 0))
		return (0);
	tmp = strjoin_ascii(cmd->infi, cmd->num);
	if (!tmp)
		return (1);
	cmd->infi = ft_strjoin("./here_doc/", tmp);
	free(tmp);
	if (!cmd->infi)
		return (1);
	cmd->limi = 1;
	return (0);
}
