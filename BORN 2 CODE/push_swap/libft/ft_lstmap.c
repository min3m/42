/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:16:52 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/16 20:21:48 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_data (*f)(t_data), void (*del)(t_data))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	new = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->data));
		if (!(temp))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
