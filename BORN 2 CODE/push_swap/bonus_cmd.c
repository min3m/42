/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:55:53 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/27 16:51:43 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_s_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a' || c == 's')
	{
		if (ft_lstsize(stack->stack_a) < 2)
			return ;
		temp = ft_pop(&(stack->stack_a), 2);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 1);
	}
	if (c == 'b' || c == 's')
	{
		if (ft_lstsize(stack->stack_b) < 2)
			return ;
		temp = ft_pop(&(stack->stack_b), 2);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 1);
	}
}

void	bonus_p_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		if (ft_lstsize(stack->stack_b) == 0)
			return ;
		temp = ft_pop(&(stack->stack_b), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 2);
	}
	else if (c == 'b')
	{
		if (ft_lstsize(stack->stack_a) == 0)
			return ;
		temp = ft_pop(&(stack->stack_a), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 2);
	}
}

void	bonus_r_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a' || c == 'r')
	{
		if (ft_lstsize(stack->stack_a) == 0)
			return ;
		temp = ft_pop(&(stack->stack_a), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 3);
	}
	if (c == 'b' || c == 'r')
	{
		if (ft_lstsize(stack->stack_b) == 0)
			return ;
		temp = ft_pop(&(stack->stack_b), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 3);
	}
}

void	bonus_rr_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a' || c == 'r')
	{
		if (ft_lstsize(stack->stack_a) == 0)
			return ;
		temp = ft_pop(&(stack->stack_a), ft_lstsize(stack->stack_a));
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 4);
	}
	if (c == 'b' || c == 'r')
	{
		if (ft_lstsize(stack->stack_b) == 0)
			return ;
		temp = ft_pop(&(stack->stack_b), ft_lstsize(stack->stack_b));
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 4);
	}
}
