/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:53:52 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 20:18:12 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	int		flag;
	t_list	*temp;

	flag = 0;
	temp = ft_pop(&(stack->stack_a), 2);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	if (ft_push(&(stack->stack_a), temp, 1))
		flag = 1;
	temp = ft_pop(&(stack->stack_b), 2);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	if (ft_push(&(stack->stack_b), temp, 1))
		ft_putendl_fd("ss", 1);
}

void	rr(t_stack *stack)
{
	int		flag;
	t_list	*temp;

	flag = 0;
	temp = ft_pop(&(stack->stack_a), 1);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	if (ft_push(&(stack->stack_a), temp, 3))
		flag = 1;
	temp = ft_pop(&(stack->stack_b), 1);
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	if (ft_push(&(stack->stack_b), temp, 3) && flag)
		ft_putendl_fd("rr", 1);
}

void	rrr(t_stack *stack)
{
	int		flag;
	t_list	*temp;

	flag = 0;
	temp = ft_pop(&(stack->stack_a), ft_lstsize(stack->stack_a));
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	if (ft_push(&(stack->stack_a), temp, 4))
		flag = 1;
	temp = ft_pop(&(stack->stack_b), ft_lstsize(stack->stack_b));
	if (!temp)
		exit_push_swap(stack, EXIT_FAILURE);
	if (ft_push(&(stack->stack_b), temp, 4) && flag)
		ft_putendl_fd("rrr", 1);
}
