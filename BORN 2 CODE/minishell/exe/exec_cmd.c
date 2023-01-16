/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:30:34 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/11 13:25:14 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	exec_cmd(t_parse **lst, t_cmd **cmd, t_cmd *cur)
{
	char	*str;
	char	**path;

	if (is_builtin_bool(cur))
		exit(is_builtin(cur));
	str = ft_getenv("PATH");
	if (!str)
		error_invalid_cmd(cur->arg[0], lst, cmd);
	path = ft_split_non(str, ':');
	if (!path)
		error_cmd(lst, cmd);
	exe_loop(lst, cmd, cur, path);
	free_split_cmd(path);
	error_invalid_cmd(cur->arg[0], lst, cmd);
}

char	**dup_arg(char **arg)
{
	int		i;
	char	**res;

	i = 0;
	while (arg[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (0);
	i = 0;
	while (arg[i])
	{
		res[i] = ft_strdup_no_gc(arg[i]);
		if (!res[i])
		{
			free_split_no_gc(res);
			return (0);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}

void	free_split_cmd(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*ft_strdup_no_gc(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest || !s1)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	free_split_no_gc(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
