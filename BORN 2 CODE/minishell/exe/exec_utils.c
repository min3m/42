/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:04:17 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 11:14:59 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	*get_cmd_path(t_cmd *cur, char **path, int i)
{
	size_t	len;
	char	*c;

	len = ft_strlen(path[i]) + ft_strlen(cur->arg[0]) + 1;
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (0);
	c[0] = 0;
	ft_strlcat(c, path[i], len + 1);
	ft_strlcat(c, "/", len + 1);
	ft_strlcat(c, cur->arg[0], len + 1);
	return (c);
}

void	exe_loop(t_parse **lst, t_cmd **cmd, t_cmd *cur, char **path)
{
	int		i;
	char	*c;

	i = 0;
	if (access(cur->arg[0], F_OK) == 0)
		execve(cur->arg[0], cur->arg, make_env(&g_minishell.env));
	while (path[i])
	{
		c = get_cmd_path(cur, path, i);
		if (!c)
		{
			free_split_cmd(path);
			error_cmd(lst, cmd);
		}
		if (access(c, F_OK) == 0)
		{
			free_split_cmd(path);
			execve(c, cur->arg, make_env(&g_minishell.env));
		}
		free(c);
		i++;
	}
}
