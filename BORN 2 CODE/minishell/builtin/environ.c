/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:38:54 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 15:04:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	ft_export(char **argv)
{
	int		i;
	char	**split_env;

	i = 0;
	split_env = split_node();
	if (argv[1])
	{
		while (argv[++i])
			if (!is_export_arg_valid(argv[i]))
				return (error_builtin_cd(": export: ", argv[i],
						": not a valid identifier"));
		i = 0;
		while (argv[++i])
			add_env(&(g_minishell.env), argv[i], 1);
	}
	else if (!argv[1])
	{
		split_env = sort_str(env_lstsize(g_minishell.env), split_env);
		print_export(split_env);
	}
	free_split(split_env);
	return (EXIT_SUCCESS);
}

int	ft_env(char **argv)
{
	t_env	*curr;

	curr = g_minishell.env;
	if (argv[1] && argv[1][0] == '-')
	{
		ft_putendl_fd("env: options should not be included", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (argv[1])
		return (is_env_arg_valid(argv));
	else
	{
		while (curr)
		{
			if (!curr->flag)
				ft_putendl_fd(curr->data, STDOUT_FILENO);
			curr = curr->next;
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(char **argv)
{
	int	i;

	i = 1;
	if (argv[i] && argv[i][0] == '-')
	{
		ft_putendl_fd("unset: options should not be included", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (argv[i])
	{
		while (argv[i])
		{
			remove_envnode(ft_strlen(argv[i]), argv[i]);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
