/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:54:30 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 10:29:05 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

t_parse	*parse_main(char *str)
{
	t_parse	*lst;
	char	*s;

	lst = 0;
	s = ft_strdup(str);
	if (!s)
		error_nothing();
	if (add_parse(&lst, s, DEFA, NONE))
	{
		free(s);
		error_nothing();
	}
	sequence(&lst);
	return (lst);
}

void	sequence(t_parse **lst)
{
	separate_quote(lst);
	trans_dollar(lst);
	separate_space(lst);
	separate_pipe(lst);
	separate_red(lst);
	del_empty(lst);
	change_able(lst);
	union_able(lst);
	del_space(lst);
	check_cmd_error(lst);
	set_cmd_error(lst);
}
