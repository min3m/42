/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:22:19 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 23:22:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	is_n_option(char *argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-')
		{
			j = i + 1;
			while (argv[j])
			{
				if (argv[j] != 'n')
					return (0);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_echo(char **argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[++i])
	{
		flag = is_n_option(argv[i]);
		if (!flag && i != 1)
		{
			flag = 1;
			break ;
		}
		else if (!flag && i == 1)
			break ;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i++], STDOUT_FILENO);
		if (argv[i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (!flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
