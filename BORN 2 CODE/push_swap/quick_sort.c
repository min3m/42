/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:25:23 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 17:02:30 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count	sort_index_b(t_stack *stack, int index, t_count count, t_pivot pivot)
{
	if (index < pivot.s)
	{
		r_(stack, 'b');
		count.rb++;
	}
	else
	{
		p_(stack, 'a');
		count.pa++;
		if (index < pivot.b)
		{
			r_(stack, 'a');
			count.ra++;
		}
	}
	return (count);
}

t_count	sort_index_a(t_stack *stack, int index, t_count count, t_pivot pivot)
{
	if (index > pivot.b)
	{
		r_(stack, 'a');
		count.ra++;
	}
	else
	{
		p_(stack, 'b');
		count.pb++;
		if (index > pivot.s)
		{
			r_(stack, 'b');
			count.rb++;
		}
	}
	return (count);
}

void	b_to_a(t_stack *stack, int num)
{
	t_pivot	pivot;
	t_count	count;
	t_list	*curr;

	if (num <= 3)
	{
		if (num == 3)
			sort_three_b(stack, ft_find_min(stack->stack_b, 3));
		else if (num == 2 || num == 1)
			sort_two(stack, num, 'b');
		return ;
	}
	pivot = set_p(stack->stack_b, num);
	set_c(&count);
	curr = stack->stack_b;
	while (curr && num--)
	{
		count = sort_index_b(stack, curr->data.index, count, pivot);
		curr = stack->stack_b;
	}
	a_to_b(stack, count.pa - count.ra);
	re_wind(stack, count.ra, count.rb);
	a_to_b(stack, count.ra);
	b_to_a(stack, count.rb);
}

void	a_to_b(t_stack *stack, int num)
{
	t_pivot	pivot;
	t_count	count;
	t_list	*curr;

	if (num <= 3)
	{
		if (num == 3)
			sort_three_a(stack, ft_find_max(stack->stack_a, 3), \
			ft_lstsize(stack->stack_a));
		else if (num == 2)
			sort_two(stack, 0, 'a');
		return ;
	}
	pivot = set_p(stack->stack_a, num);
	set_c(&count);
	curr = stack->stack_a;
	while (curr && num--)
	{
		count = sort_index_a(stack, curr->data.index, count, pivot);
		curr = stack->stack_a;
	}
	re_wind(stack, count.ra, count.rb);
	a_to_b(stack, count.ra);
	b_to_a(stack, count.rb);
	b_to_a(stack, count.pb - count.rb);
}

void	quick_sort(t_stack *stack)
{
	a_to_b(stack, ft_lstsize(stack->stack_a));
}
