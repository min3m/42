/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:23:28 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/24 20:23:16 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack, int num, char c)
{
	if (c == 'a')
	{
		if (stack->stack_a->data.index > stack->stack_a->next->data.index)
			s_(stack, 'a');
	}
	else if (c == 'b')
	{
		if (num == 2)
		{
			if (stack->stack_b->data.index < stack->stack_b->next->data.index)
				s_(stack, 'b');
			p_(stack,'a');
			p_(stack,'a');
		}
		else if (num == 1)
			p_(stack,'a');
	}
}

void	sort_five(t_stack *stack, int count, int min)
{
	int		i;
	t_list	*curr;

	if (count < 3)
		return ;
	i = 0;
	curr = stack->stack_a;
	while (curr)
	{
		if (curr->data.index == min)
			break ;
		i++;
		curr = curr->next;
	}
	if (i <= 2)
		while (i--)
			r_(stack, 'a');
	else
	{
		i = count - i + 1;
		while (i--)
			rr_(stack, 'a');
	}
	p_(stack, 'b');
	sort_five(stack, count - 1, 1);
}

void	sort_three_a(t_stack *stack, int count, int size)
{
	if (stack->stack_a->data.index == count && size == 3)
		r_(stack, 'a');
	if (stack->stack_a->next->data.index == count && size == 3)
		rr_(stack, 'a');
	if (stack->stack_a->data.index > stack->stack_a->next->data.index \
	&& size == 3)
		s_(stack, 'a');
	if (stack->stack_a->next->data.index == count)
	{
		r_(stack, 'a');
		s_(stack, 'a');
		rr_(stack, 'a');
	}
	if (stack->stack_a->data.index == count)
	{
		s_(stack, 'a');
		r_(stack, 'a');
		s_(stack, 'a');
		rr_(stack, 'a');
	}
	if (stack->stack_a->data.index > stack->stack_a->next->data.index)
		s_(stack, 'a');
}

void	sort_three_b(t_stack *stack, int count)
{
	int	flag;
	int	num;

	flag = 0;
	num = 3;
	if (stack->stack_b->next->data.index == count)
		s_(stack, 'b');
	if (stack->stack_b->data.index == count)
	{
		r_(stack, 'b');
		flag = 1;
	}
	if (stack->stack_b->data.index < stack->stack_b->next->data.index)
		s_(stack, 'b');
	if (flag)
	{
		num = 2;
		while (num--)
			p_(stack, 'a');
		rr_(stack, 'b');
		p_(stack, 'a');
		return ;
	}
	while (num--)
		p_(stack, 'a');
}

void	sort_arg(t_stack *stack)
{
	int	count;

	count = ft_lstsize(stack->stack_a);
	if (count <= 5)
	{
		if (count == 2)
			sort_two(stack, 0, 'a');
		else
		{
			sort_five(stack, count - 1, 0);
			sort_three_a(stack, count - 1, 3);
			count -= 3;
			while (count--)
				p_(stack, 'a');
		}
	}
	else
		quick_sort(stack);
}
