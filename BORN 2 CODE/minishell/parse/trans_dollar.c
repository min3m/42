/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:01:15 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 15:08:23 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	trans_dollar(t_parse **lst)
{
	t_parse	*cur;
	char	**seg;
	char	*s;

	cur = *lst;
	while (cur)
	{
		if (cur->in_quote != SING)
		{
			seg = split_dollar(cur->s);
			if (!seg)
				error_parse(lst);
			trand_dollar_loop(lst, seg);
			s = ft_join_split(seg);
			if (!s)
				error_seg_malloc(lst, seg);
			free(cur->s);
			cur->s = s;
		}
		cur = cur->next;
	}
}

void	trand_dollar_loop(t_parse **lst, char **seg)
{
	int	i;

	i = 0;
	while (seg[i])
	{
		change_dollar(lst, seg, i);
		i++;
	}
}

char	*ft_join_split(char **seg)
{
	int		i;
	char	*res;
	char	*s;

	i = 0;
	res = ft_strdup("");
	if (!res)
		return (0);
	while (seg[i])
	{
		s = ft_strjoin(res, seg[i]);
		free(res);
		if (!s)
			return (0);
		res = s;
		i++;
	}
	free_split(seg);
	return (res);
}

void	change_dollar(t_parse **lst, char **seg, int i)
{
	char	*s;

	if (i % 2 == 1)
	{
		if (seg[i][1] == 0)
			;
		else if (seg[i][1] == '?')
		{
			free(seg[i]);
			seg[i] = ft_itoa(g_minishell.last_state);
			if (!seg[i])
				error_seg_malloc(lst, seg);
		}
		else
		{
			s = ft_getenv(seg[i] + 1);
			if (!s)
				s = "";
			s = ft_strdup(s);
			if (!s)
				error_seg_malloc(lst, seg);
			free(seg[i]);
			seg[i] = s;
		}
	}
}

void	error_seg_malloc(t_parse **lst, char **seg)
{
	free_split(seg);
	error_parse(lst);
}
