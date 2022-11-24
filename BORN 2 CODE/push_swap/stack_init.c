/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:12:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/18 16:03:31 by youngmch         ###   ########.fr       */
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
	// t_list *curr;
	// for (curr = stack->stack_a ; curr != NULL ; curr=curr->next)
	// 		printf("%d ",curr->data.index);
	return (stack);
}
