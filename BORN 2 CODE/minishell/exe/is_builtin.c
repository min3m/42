/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:22 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 10:47:58 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	is_builtin(t_cmd *cur)
{
	if (ft_strcmp("echo", cur->arg[0]) == 0)
		return (ft_echo(cur->arg));
	if (ft_strcmp("cd", cur->arg[0]) == 0)
		return (ft_cd(cur->arg));
	if (ft_strcmp("pwd", cur->arg[0]) == 0)
		return (ft_pwd(cur->arg));
	if (ft_strcmp("export", cur->arg[0]) == 0)
		return (ft_export(cur->arg));
	if (ft_strcmp("unset", cur->arg[0]) == 0)
		return (ft_unset(cur->arg));
	if (ft_strcmp("env", cur->arg[0]) == 0)
		return (ft_env(cur->arg));
	if (ft_strcmp("exit", cur->arg[0]) == 0)
		return (ft_exit(cur->arg));
	return (0);
}

int	is_builtin_bool(t_cmd *cur)
{
	if (ft_strcmp("echo", cur->arg[0]) == 0)
		return (1);
	if (ft_strcmp("cd", cur->arg[0]) == 0)
		return (1);
	if (ft_strcmp("pwd", cur->arg[0]) == 0)
		return (1);
	if (ft_strcmp("export", cur->arg[0]) == 0)
		return (1);
	if (ft_strcmp("unset", cur->arg[0]) == 0)
		return (1);
	if (ft_strcmp("env", cur->arg[0]) == 0)
		return (1);
	if (ft_strcmp("exit", cur->arg[0]) == 0)
		return (1);
	return (0);
}
