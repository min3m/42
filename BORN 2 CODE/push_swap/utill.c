/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:19:08 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/24 16:17:05 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **stack, t_list *new, int flag)
{
	if (!new)
		return (0);
	if ((*stack) == NULL)
		ft_lstadd_front(stack, new);
	else if (flag == 1 || flag == 2 || flag == 4)
		ft_lstadd_front(stack, new);
	else if (flag == 3)
		ft_lstadd_back(stack, new, 0);
	return (1);
}

t_list	*ft_pop(t_list **stack, int index)
{
	t_list	*curr;
	t_data	temp;

	curr = *stack;
	while (curr->next && --index)
		curr = curr->next;
	temp = curr->data;
	ft_lstdelone(stack, curr);
	return (ft_lstnew(temp));
}
