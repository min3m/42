/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:59:50 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/09 22:43:59 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	error_cmd(t_parse **lst, t_cmd **cmd)
{
	ft_putstr_fd(g_minishell.shell_name, STDERR_FILENO);
	ft_putendl_fd(": memory allocation failed", STDERR_FILENO);
	clear_cmd(cmd);
	clear_parse(lst);
	exit(1);
}
