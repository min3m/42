/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:02:39 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 15:09:04 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	*here_doc_dollar(char *s)
{
	int		i;
	char	**segment;
	char	*res;

	segment = set_here_doc_seg(s);
	if (!segment)
		return (0);
	i = 0;
	while (segment[i])
	{
		if (here_doc_change_dollar(segment, i))
		{
			free_split(segment);
			return (0);
		}
		i++;
	}
	res = ft_join_split(segment);
	if (!res)
		return (0);
	return (res);
}

char	**set_here_doc_seg(char *s)
{
	int		seg;
	int		i;
	char	**segment;
	int		blk;

	seg = 0;
	i = 0;
	get_seg_dollar(s, &i, &seg);
	seg = (seg * 2) + 1;
	segment = malloc(sizeof(char *) * (seg + 1));
	if (!segment)
		return (0);
	blk = 0;
	i = 0;
	while (blk < seg)
	{
		if (set_here_doc_start_end(s, &i, &blk, &segment))
			return (0);
	}
	segment[blk] = 0;
	return (segment);
}

int	set_here_doc_start_end(char *s, int *i, int *blk, char ***segment)
{
	if (set_start_end_dollar_here(s, i, blk, segment))
	{
		free_split(*segment);
		return (1);
	}
	(*blk)++;
	return (0);
}

int	here_doc_change_dollar(char **seg, int i)
{
	char	*s;

	if (i % 2 != 1)
		return (0);
	if (seg[i][1] == 0)
		;
	else if (seg[i][1] == '?')
	{
		free(seg[i]);
		seg[i] = ft_itoa(g_minishell.last_state);
		if (!seg[i])
			return (1);
	}
	else
	{
		s = ft_getenv(seg[i] + 1);
		if (!s)
			s = "";
		s = ft_strdup(s);
		if (!s)
			return (here_doc_dollar_tmp(seg));
		free(seg[i]);
		seg[i] = s;
	}
	return (0);
}
