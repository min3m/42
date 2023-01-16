/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:23:41 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	check_cmd_error(t_parse **lst)
{
	t_parse	*cur;
	t_parse	*pre;

	cur = *lst;
	pre = 0;
	while (cur)
	{
		if (cur->type == REDD)
		{
			if (!cur->next)
				cur->type = ERRO;
			if (cur->next && cur->next->type != ABLE)
				cur->type = ERRO;
		}
		else if (cur->type == PIPE)
		{
			if (!cur->next)
				cur->type = ERRO;
			if (!pre || (pre && pre->type != ABLE))
				cur->type = ERRO;
		}
		pre = cur;
		cur = cur->next;
	}
}

void	set_cmd_error(t_parse **lst)
{
	t_parse	*cur;
	char	*blame;

	cur = *lst;
	while (cur)
	{
		if (cur->type == ERRO)
		{
			if (cur->next)
				blame = ft_strdup(cur->next->s);
			else
				blame = ft_strdup("\\n");
			if (!blame)
				error_parse(lst);
			clear_parse(&cur->next);
			free(cur->s);
			cur->s = blame;
			break ;
		}
		cur = cur->next;
	}
}
