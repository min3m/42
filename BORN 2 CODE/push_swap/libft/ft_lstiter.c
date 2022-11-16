/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:03:15 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/16 20:19:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, t_data (*f)(t_data))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}
