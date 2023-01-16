/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:37:08 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 21:15:19 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	change_envnode(t_env **list, char *flag, char *path)
{
	t_env	*new;
	t_env	*temp;
	char	*line;

	temp = (*list)->next;
	line = ft_strjoin(flag, path);
	if (!line)
		error_init();
	new = ft_malloc(sizeof(t_env));
	if (!new)
	{
		ft_free(line);
		error_env(&(g_minishell.env), new);
	}
	new->data = ft_strdup(line);
	ft_free(line);
	if (!(new->data))
		error_env(&(g_minishell.env), new);
	new->next = (*list)->next->next;
	(*list)->next = new;
	delone_env(temp);
}

void	clear_env(t_env **list)
{
	t_env	*curr;

	if (!(*list))
		return ;
	while (*list)
	{
		curr = *list;
		*list = (*list)->next;
		delone_env(curr);
	}
}

void	delone_env(t_env *list)
{
	if (list->data)
		ft_free(list->data);
	ft_free(list);
}

t_env	*last_env(t_env *curr)
{
	if (!curr)
		return (curr);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

int	add_env(t_env **env_list, char *line, int flag)
{
	t_env	*env;
	t_env	*curr;

	if (is_env_node_same(env_list, line))
		return (1);
	env = ft_malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->flag = 0;
	if (flag && !ft_strchr(line, '='))
		env->flag = 1;
	env->data = ft_strdup(line);
	if (!env->data)
		error_env(env_list, env);
	env->next = NULL;
	curr = *env_list;
	curr = last_env(curr);
	if (!curr)
		*env_list = env;
	else
		curr->next = env;
	return (1);
}
