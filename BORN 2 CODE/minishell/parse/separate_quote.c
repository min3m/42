/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:49:28 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	separate_quote(t_parse **lst)
{
	t_parse	*cur;
	int		i;

	cur = *lst;
	while (cur)
	{
		while (cur && cur->type != DEFA)
			cur = cur->next;
		if (!cur)
			break ;
		i = 0;
		while (cur->s[i] && cur->s[i] != '\"' && cur->s[i] != '\'')
			i++;
		if (cur->s[i] == '\'' || cur->s[i] == '\"')
			separate_by_quote(lst, &cur, i, cur->s[i]);
		cur = cur->next;
	}
}

void	separate_by_quote(t_parse **lst, t_parse **cur, int i, char flag)
{
	int		open;
	int		close;
	char	**sep;

	open = i;
	i++;
	while ((*cur)->s[i] && (*cur)->s[i] != flag)
		i++;
	if ((*cur)->s[i] == flag)
		close = i;
	else
	{
		(*cur)->type = ERRO;
		return ;
	}
	sep = dividing(lst, (*cur)->s, open, close);
	free((*cur)->s);
	(*cur)->s = sep[0];
	if (flag == '\'')
		try_sing(lst, cur, sep);
	else if (flag == '\"')
		try_doub(lst, cur, sep);
	try_last(lst, cur, sep);
	free(sep);
}

char	**dividing(t_parse **lst, char *s, int open, int close)
{
	char	**res;

	res = malloc(sizeof(char *) * 3);
	if (!res)
		error_parse(lst);
	res[0] = ft_strndup(s, open);
	res[1] = ft_strndup(s + open + 1, close - open - 1);
	res[2] = ft_strndup(s + close + 1, ft_strlen(s) - close - 1);
	if (!res[0] || !res[1] || !res[2])
	{
		if (res[0])
			free(res[0]);
		if (res[1])
			free(res[1]);
		if (res[2])
			free(res[2]);
		free(res);
		error_parse(lst);
	}
	return (res);
}
