/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:01:15 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	**split_dollar(char *s)
{
	int		i;
	int		seg;
	char	**res;
	int		blk;

	seg = 0;
	i = 0;
	get_seg_dollar(s, &i, &seg);
	seg = (seg * 2) + 1;
	res = malloc(sizeof(char *) * (seg + 1));
	if (!res)
		return (0);
	blk = 0;
	i = 0;
	while (blk < seg)
	{
		if (set_start_end_dollar(s, &i, &blk, &res))
		{
			free_split(res);
			return (0);
		}
		blk++;
	}
	res[blk] = 0;
	return (res);
}

void	get_seg_dollar(char *s, int *i, int *seg)
{
	while (s[*i])
	{
		if (s[*i] == '$')
			(*seg)++;
		(*i)++;
	}
}

int	set_start_end_dollar(char *s, int *i, int *blk, char ***res)
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
			while (s[*i] && s[*i] != '$' && s[*i] != '<' && s[*i] != '>'
				&& s[*i] != '|' && s[*i] != ' ')
				(*i)++;
		}
	}
	end = *i;
	(*res)[*blk] = ft_strndup(s + start, end - start);
	if (error_res(res, blk))
		return (1);
	return (0);
}

int	error_res(char ***res, int *blk)
{
	if (!((*res)[*blk]))
	{
		while (*blk > 0)
			free((*res)[--(*blk)]);
		free(*res);
		return (1);
	}
	return (0);
}

void	free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i])
			free(res[i]);
		i++;
	}
	free(res);
}
