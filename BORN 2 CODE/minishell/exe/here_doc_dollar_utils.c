/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_dollar_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:02:39 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/08 21:14:36 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	here_doc_dollar_tmp(char **seg)
{
	free_split(seg);
	return (1);
}

int	set_start_end_dollar_here(char *s, int *i, int *blk, char ***res)
{
	int	start;
	int	end;

	start = *i;
	if (!(*blk % 2))
	{
		while (s[*i] && s[*i] != '$')
			(*i)++;
	}
	else
	{
		if (s[++(*i)] == '?')
			(*i)++;
		else
		{
			while (s[*i] && s[*i] != '$' && s[*i] != ' ' && s[*i] != '\n')
				(*i)++;
		}
	}
	end = *i;
	(*res)[*blk] = ft_strndup(s + start, end - start);
	if (error_res(res, blk))
		return (1);
	return (0);
}
