/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:12:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/16 21:57:42 by youngmch         ###   ########.fr       */
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
	while (arr[i])
	{
		data.value = ft_atoi(arr[i]);
		data.index = 0;
		ft_lstadd_back(&(stack->stack_a), ft_lstnew(data));
		i++;
	}
	// printf("%d\n",ft_lstsize(stack->stack_a));
	t_list *curr;
	for (curr = stack->stack_a ; curr != NULL ; curr=curr->next)
			printf("%d ",curr->data.index);
	return (stack);
}
