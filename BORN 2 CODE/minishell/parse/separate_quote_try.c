/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_quote_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:49:28 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	try_sing(t_parse **lst, t_parse **cur, char **sep)
{
	if (add_parse(cur, sep[1], ABLE, SING))
	{
		free(sep[1]);
		free(sep[2]);
		free(sep);
		error_parse(lst);
	}
}

void	try_doub(t_parse **lst, t_parse **cur, char **sep)
{
	if (add_parse(cur, sep[1], ABLE, DOUB))
	{
		free(sep[1]);
		free(sep[2]);
		free(sep);
		error_parse(lst);
	}
}

void	try_last(t_parse **lst, t_parse **cur, char **sep)
{
	if (add_parse(cur, sep[2], DEFA, NONE))
	{
		free(sep[2]);
		free(sep);
		error_parse(lst);
	}
}
