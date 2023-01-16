/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:01:15 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	separate_red(t_parse **lst)
{
	t_parse	*cur;
	char	**seg;
	int		i;

	cur = *lst;
	while (cur)
	{
		if (cur->type == DEFA)
		{
			seg = split_red(cur->s);
			if (!seg)
				error_parse(lst);
			free(cur->s);
			cur->s = seg[0];
			i = 1;
			while (seg[i])
			{
				separate_red_loop(lst, &cur, seg, i);
				i++;
			}
			free(seg);
		}
		cur = cur->next;
	}
}

void	separate_red_loop(t_parse **lst, t_parse **cur, char **seg, int i)
{
	t_parse	*new;

	if (seg[i][0] == '<' || seg[i][0] == '>')
		new = new_parse(seg[i], REDD, NONE);
	else
		new = new_parse(seg[i], DEFA, NONE);
	if (!new)
		error_seg_malloc(lst, seg);
	new->next = (*cur)->next;
	(*cur)->next = new;
	(*cur) = (*cur)->next;
}

char	**split_red(char *s)
{
	int		i;
	int		seg;
	char	**res;
	int		blk;

	seg = 0;
	i = 0;
	get_seg_red(s, &i, &seg);
	seg = (seg * 2) + 1;
	res = malloc(sizeof(char *) * (seg + 1));
	if (!res)
		return (0);
	blk = 0;
	i = 0;
	while (blk < seg)
	{
		if (set_start_end_red(s, &i, &blk, &res))
			return (0);
		blk++;
	}
	res[blk] = 0;
	return (res);
}

void	get_seg_red(char *s, int *i, int *seg)
{
	while (s[*i])
	{
		if (s[*i] == '<')
		{
			if (s[*i + 1] && s[*i + 1] == '<')
				(*i)++;
			(*seg)++;
		}
		else if (s[*i] == '>')
		{
			if (s[*i + 1] && s[*i + 1] == '>')
				(*i)++;
			(*seg)++;
		}
		(*i)++;
	}
}

int	set_start_end_red(char *s, int *i, int *blk, char ***res)
{
	int		start;
	int		end;
	char	ck;

	if (!(*blk % 2))
	{
		start = *i;
		while (s[*i] && s[*i] != '<' && s[*i] != '>')
			(*i)++;
		end = *i;
	}
	else
	{
		start = *i;
		ck = s[*i];
		if (*i == start)
			(*i)++;
		if (s[*i] && s[*i] == ck)
			(*i)++;
		end = *i;
	}
	(*res)[*blk] = ft_strndup(s + start, end - start);
	if (error_res(res, blk))
		return (1);
	return (0);
}
