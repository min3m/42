/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:01:12 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	separate_space(t_parse **lst)
{
	t_parse	*cur;
	char	**seg;
	int		i;

	cur = *lst;
	while (cur)
	{
		if (cur->type == DEFA)
		{
			seg = split_space(cur->s);
			if (!seg)
				error_parse(lst);
			free(cur->s);
			cur->s = seg[0];
			i = 1;
			while (seg[i])
			{
				separate_space_loop(lst, &cur, seg, i);
				i++;
			}
			free(seg);
		}
		cur = cur->next;
	}
}

void	separate_space_loop(t_parse **lst, t_parse **cur, char **seg, int i)
{
	t_parse	*new;

	if (seg[i][0] == ' ')
		new = new_parse(seg[i], SPCE, NONE);
	else
		new = new_parse(seg[i], DEFA, NONE);
	if (!new)
		error_seg_malloc(lst, seg);
	new->next = (*cur)->next;
	(*cur)->next = new;
	(*cur) = (*cur)->next;
}

char	**split_space(char *s)
{
	int		i;
	int		seg;
	char	**res;
	int		blk;

	seg = 0;
	i = 0;
	get_seg_space(s, &i, &seg);
	seg = (seg * 2) + 1;
	res = malloc(sizeof(char *) * (seg + 1));
	if (!res)
		return (0);
	blk = 0;
	i = 0;
	while (blk < seg)
	{
		if (set_start_end_space(s, &i, &blk, &res))
			return (0);
		blk++;
	}
	res[blk] = 0;
	return (res);
}

void	get_seg_space(char *s, int *i, int *seg)
{
	while (s[*i])
	{
		if (s[*i] == ' ')
			(*seg)++;
		(*i)++;
	}
}

int	set_start_end_space(char *s, int *i, int *blk, char ***res)
{
	int	start;
	int	end;

	if (!(*blk % 2))
	{
		start = *i;
		while (s[*i] && s[*i] != ' ')
			(*i)++;
		end = *i;
	}
	else
	{
		start = *i;
		if (*i == start)
			(*i)++;
		end = *i;
	}
	(*res)[*blk] = ft_strndup(s + start, end - start);
	if (error_res(res, blk))
		return (1);
	return (0);
}
