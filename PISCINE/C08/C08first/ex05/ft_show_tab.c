/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:11:28 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/07 20:16:29 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_print_num(int num)
{
	if (num == 0)
		return ;
	ft_print_num(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_print(par[i].str);
		write(1, "\n", 1);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			ft_print_num(par[i].size);
		write(1, "\n", 1);
		ft_print(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
