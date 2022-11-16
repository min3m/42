/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:26:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/16 17:39:16 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argu_init(char **argv)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**arr;

	i = 1;
	str = ft_strdup("");
	while (argv[i])
	{
		tmp = str;
		str = ft_strjoin(str, argv[i]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	return (arr);
}

int main(int argc, char **argv)
{
	int		i;
	char	**arr;
	t_stack	*stack;

	i = -1;
	if (argc >= 2)
	{
		while (argv[++i])
		{
			if (!(ft_strncmp(argv[i], "", ft_strlen(argv[i]))))
				exit(ft_putendl_fd("Error", 1));
		}
		arr = argu_init(argv);
		check_argu(argc, arr);
		stack = stack_init(arr);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
