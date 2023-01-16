/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:28:58 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 15:05:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	**sort_str(int size, char **str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(str[i], str[j]) > 0)
			{
				temp = str[j];
				str[j] = str[i];
				str[i] = temp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

char	**split_node(void)
{
	int		i;
	t_env	*curr;
	char	**split_lst;
	int		lst_size;

	curr = g_minishell.env;
	lst_size = env_lstsize(curr);
	split_lst = ft_malloc(sizeof(char *) * (lst_size + 1));
	if (!split_lst)
		error_init();
	split_lst[lst_size] = 0;
	i = -1;
	while (curr)
	{
		split_lst[++i] = ft_strdup(curr->data);
		if (!split_lst[i])
		{
			free_split(split_lst);
			error_init();
		}
		curr = curr->next;
	}
	return (split_lst);
}

int	is_env_arg_valid(char **argv)
{
	int		i;
	char	*equal;
	t_env	*curr;

	i = 0;
	while (argv[++i])
	{
		equal = ft_strchr(argv[i], '=');
		if (!equal)
			return (error_builtin_env(": env: ", argv[i],
					": No such file or direcotry"));
	}
	curr = g_minishell.env;
	while (curr)
	{
		ft_putendl_fd(curr->data, STDOUT_FILENO);
		curr = curr->next;
	}
	i = -1;
	while (argv[++i])
		ft_putendl_fd(argv[i], STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

void	remove_envnode(size_t len, char *argv)
{
	t_env	*curr;
	t_env	*temp;

	curr = g_minishell.env;
	if (!ft_strncmp(curr->data, argv, len)
		&& *(curr->data + len) == '=')
	{
		temp = g_minishell.env;
		g_minishell.env = g_minishell.env->next;
		delone_env(temp);
		return ;
	}
	while (curr->next)
	{
		if (!ft_strncmp(curr->next->data, argv, len)
			&& *(curr->next->data + len) == '=')
		{
			temp = curr->next;
			curr->next = curr->next->next;
			delone_env(temp);
			return ;
		}
		curr = curr->next;
	}
}
