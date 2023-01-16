/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:03:09 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/12 15:03:51 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	dup2_std_to_bp(void)
{
	dup2(g_minishell.bp_stdin, STDIN_FILENO);
	dup2(g_minishell.bp_stdout, STDOUT_FILENO);
}

void	signal_init(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

int	is_env_node_same(t_env **env_list, char *line)
{
	int		i;
	t_env	*curr;

	curr = *env_list;
	while (curr)
	{
		i = 0;
		while (line[i] && curr->data[i] && curr->data[i] == line[i])
		{
			if (curr->data[i + 1] == '=' && !line[i + 1])
				return (1);
			if ((!curr->data[i + 1] && line[i + 1] == '=')
				|| (curr->data[i] == '=' && line[i] == '='))
			{
				ft_free(curr->data);
				curr->data = ft_strdup(line);
				if (line[i] == '=' || line[i + 1] == '=')
					curr->flag = 0;
				return (1);
			}
			i++;
		}
		curr = curr->next;
	}
	return (0);
}
