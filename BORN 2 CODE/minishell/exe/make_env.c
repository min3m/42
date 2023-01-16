/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:09:19 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 11:13:01 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	**make_env(t_env **env)
{
	t_env	*cur;
	int		i;
	char	**res;

	cur = *env;
	i = 0;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (0);
	cur = *env;
	i = 0;
	while (cur)
	{
		res[i] = cur->data;
		cur = cur->next;
		i++;
	}
	res[i] = 0;
	return (res);
}
