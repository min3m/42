/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:59:43 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 16:59:00 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_wind(t_stack *stack, int ra, int rb)
{
	int	temp;

	if (ra >= rb)
	{
		temp = ra - rb;
		while (rb--)
			rrr(stack);
		while (ft_lstsize(stack->stack_a) > 3 && temp--)
			rr_(stack, 'a');
	}
	else
	{
		temp = rb - ra;
		while (ra--)
			rrr(stack);
		while (ft_lstsize(stack->stack_b) > 3 && temp--)
			rr_(stack, 'b');
	}
}

int	ft_find_min(t_list *stack, int count)
{
	int		min;
	t_list	*curr;

	min = stack->data.index;
	curr = stack->next;
	while (curr && --count)
	{
		if (min > curr->data.index)
			min = curr->data.index;
		curr = curr->next;
	}
	return (min);
}

int	ft_find_max(t_list *stack, int count)
{
	int		max;
	t_list	*curr;

	max = stack->data.index;
	curr = stack->next;
	while (curr && --count)
	{
		if (max < curr->data.index)
			max = curr->data.index;
		curr = curr->next;
	}
	return (max);
}

t_pivot	set_p(t_list *stack, int count)
{
	t_pivot	pivot;

	pivot.s = ft_find_max(stack, count) - (count / 3) * 2;
	pivot.b = ft_find_max(stack, count) - (count / 3);
	return (pivot);
}

void	set_c(t_count *c)
{
	c->ra = 0;
	c->pb = 0;
	c->rb = 0;
	c->pa = 0;
}
