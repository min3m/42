/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:04:03 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 22:06:45 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_ss(t_stack *stack)
{
	t_list	*temp;

	temp = ft_pop(&(stack->stack_a), 2);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	ft_push(&(stack->stack_a), temp, 1);
	temp = ft_pop(&(stack->stack_b), 2);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	ft_push(&(stack->stack_b), temp, 1);
}

void	bonus_rr(t_stack *stack)
{
	t_list	*temp;

	temp = ft_pop(&(stack->stack_a), 1);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	ft_push(&(stack->stack_a), temp, 3);
	temp = ft_pop(&(stack->stack_b), 1);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	t_push(&(stack->stack_b), temp, 3);
}

void	bonus_rrr(t_stack *stack)
{
	t_list	*temp;

	temp = ft_pop(&(stack->stack_a), ft_lstsize(stack->stack_a));
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	ft_push(&(stack->stack_a), temp, 4);
	temp = ft_pop(&(stack->stack_b), ft_lstsize(stack->stack_b));
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	ft_push(&(stack->stack_b), temp, 4);
}

