/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:55:53 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 22:08:07 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_s_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_a), 2);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 1);
	}
	else if (c == 'b')
	{
		temp = ft_pop(&(stack->stack_b), 2);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 1);
	}
	else if (c == 's')
		bonus_ss(stack);
}

void	bonus_p_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_b), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 2);
	}
	else if (c == 'b')
	{
		temp = ft_pop(&(stack->stack_a), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 2);
	}
}

void	bonus_r_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_a), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 3);
	}
	else if (c == 'b')
	{
		temp = ft_pop(&(stack->stack_b), 1);
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 3);
	}
	else if (c == 'r')
		bonus_rr(stack);
}

void	bonus_rr_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_a), ft_lstsize(stack->stack_a));
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_a), temp, 4);
	}
	else if (c == 'b')
	{
		temp = ft_pop(&(stack->stack_b), ft_lstsize(stack->stack_b));
		if (!temp)
			exit_push_swap(stack, EXIT_FAILURE);
		ft_push(&(stack->stack_b), temp, 4);
	}
	else if (c == 'r')
		bonus_rrr(stack);
}

