/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:21:38 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 21:21:58 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(char **arr)
{
	int		i;
	t_data	data;
	t_stack	*stack;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		free_arr(arr);
		exit(EXIT_FAILURE);
	}
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	while (arr[i])
	{
		data.value = ft_atoi(arr[i]);
		data.index = 0;
		ft_lstadd_back(&(stack->stack_a), ft_lstnew(data), 1);
		i++;
	}
	free_arr(arr);
	return (stack);
}

char	**arg_init(char **argv)
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
		str = ft_strjoin(str, argv[i++]);
		if (!str)
			exit(EXIT_FAILURE);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		if (!str)
			exit(EXIT_FAILURE);
		free(tmp);
	}
	arr = ft_split(str, ' ');
	free(str);
	if (!arr)
		exit(EXIT_FAILURE);
	return (arr);
}
