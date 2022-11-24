/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:06:30 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/23 20:34:49 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_a), 2);
		if (ft_push(&(stack->stack_a), temp, 1))
			ft_putendl_fd("sa", 1);
	}
	else
	{
		temp = ft_pop(&(stack->stack_b), 2);
		if (ft_push(&(stack->stack_b), temp, 1))
			ft_putendl_fd("sb", 1);
	}
}

void	p_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_b), 1);
		if (ft_push(&(stack->stack_a), temp, 2))
			ft_putendl_fd("pa", 1);
	}
	else
	{
		temp = ft_pop(&(stack->stack_a), 1);
		if (ft_push(&(stack->stack_b), temp, 2))
			ft_putendl_fd("pb", 1);
	}
}

void	r_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_a), 1);
		if (ft_push(&(stack->stack_a), temp, 3))
			ft_putendl_fd("ra", 1);
	}
	else
	{
		temp = ft_pop(&(stack->stack_b), 1);
		if (ft_push(&(stack->stack_b), temp, 3))
			ft_putendl_fd("rb", 1);
	}
}

void	rr_(t_stack *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		temp = ft_pop(&(stack->stack_a), ft_lstsize(stack->stack_a));
		if (ft_push(&(stack->stack_a), temp, 4))
			ft_putendl_fd("rra", 1);
	}
	else
	{
		temp = ft_pop(&(stack->stack_b), ft_lstsize(stack->stack_b));
		if (ft_push(&(stack->stack_b), temp, 4))
			ft_putendl_fd("rrb", 1);
	}
}
