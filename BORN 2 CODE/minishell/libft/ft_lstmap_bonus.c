/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:27:43 by dongyoki          #+#    #+#             */
/*   Updated: 2022/11/11 14:56:08 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*tmp_c;

	res = 0;
	while (lst)
	{
		tmp_c = f(lst->content);
		tmp = ft_lstnew(tmp_c);
		if (!tmp)
		{
			ft_lstclear(&res, del);
			del(tmp_c);
			break ;
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
