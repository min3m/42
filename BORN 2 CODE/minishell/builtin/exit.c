/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:26:46 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 20:15:00 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>

extern t_global	g_minishell;

int	ft_atoll(char *str)
{
	int					sign;
	int					i;
	unsigned long long	num;

	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == -1 && num > (unsigned long long)LLONG_MIN)
			|| (sign == 1 && num > (unsigned long long)LLONG_MAX))
			return (0);
		i++;
	}
	if (!str[i])
	{
		g_minishell.last_state = num;
		return (1);
	}
	return (0);
}

int	ft_exit(char **argv)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	g_minishell.last_state = 0;
	if (argv[1] && !ft_atoll(argv[1]))
	{
		g_minishell.last_state = 255;
		error_builtin_exit(": exit: ", argv[1], ": numeric argument required");
	}
	if (argv[1] && argv[2])
	{
		g_minishell.last_state = 1;
		return (error_builtin_exit(": exit: ", "", "too many arguments"));
	}
	if (argv[1])
	{
		if (!ft_atoll(argv[1]))
			error_builtin_exit(": exit: ", argv[1],
				": numeric argument required");
	}
	exit (g_minishell.last_state % 256);
}
