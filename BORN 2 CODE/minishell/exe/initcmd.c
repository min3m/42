/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:06:03 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/11 14:45:38 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

t_cmd	*initcmd(t_parse **lst)
{
	t_cmd	*cmd;
	t_cmd	*cur;

	cmd = make_cmd_list(lst);
	cur = cmd;
	while (cur)
	{
		if (pipe(cur->fd) == -1)
			error_strerror(lst, &cmd);
		if (file_exist(lst, &cmd, cur))
			return (0);
		init_file_fd(lst, &cmd, cur);
		cur = cur->next;
	}
	return (cmd);
}

int	file_exist(t_parse **lst, t_cmd **cmd, t_cmd *cur)
{
	int	i;

	i = 0;
	while (cur->red[i].red)
	{
		if (cur->red[i].red[0] == '<' && cur->red[i].red[1] == 0)
		{
			if (cur->red[i].red[1] == 0)
			{
				if (access(cur->red[i].file, R_OK) == -1)
					return (error_file(cur->red[i].file, lst, cmd));
			}
		}
		else if (cur->red[i].red[0] == '>')
		{
			if (access(cur->red[i].file, F_OK) == 0 && access(cur->red[i].file,
					W_OK) == -1)
				return (error_file(cur->red[i].file, lst, cmd));
		}
		i++;
	}
	return (0);
}

void	init_file_fd(t_parse **lst, t_cmd **cmd, t_cmd *cur)
{
	if (cur->rein)
	{
		if (cur->rein[1] == 0)
		{
			cur->infd = open(cur->infi, O_RDONLY);
			if (cur->infd < 0)
				exit(error_file(cur->infi, lst, cmd));
		}
	}
	if (cur->reou)
	{
		if (cur->reou[1] == 0)
			cur->oufd = open(cur->oufi, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
			cur->oufd = open(cur->oufi, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (cur->oufd < 0)
			exit (error_file(cur->oufi, lst, cmd));
	}
}
