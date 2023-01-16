/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:30:09 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/12 15:19:28 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	is_export_arg_valid(char *argv)
{
	int	i;

	if (argv[0] != '_' && !ft_isalpha(argv[0]))
		return (0);
	if (argv[0] == '_' && argv[1] == '=' && argv[2] == '0')
		return (1);
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '=')
			return (1);
		if (argv[i] != '_' && !ft_isalnum(argv[i]) && argv[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

void	print_export(char **str)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '=' || (!str[i][j + 1] && flag))
			{
				ft_putchar_fd(str[i][j], STDOUT_FILENO);
				if (ft_strchr(str[i], '='))
					ft_putchar_fd('"', STDOUT_FILENO);
				flag = 1;
			}
			else
				ft_putchar_fd(str[i][j], STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

int	count_str(char **str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	env_lstsize(t_env *lst)
{
	int	res;

	res = 0;
	while (lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}
