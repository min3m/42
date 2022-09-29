/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:29 by youngmch          #+#    #+#             */
/*   Updated: 2022/09/29 21:37:50 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long num_l)
{
	int	n_len;

	n_len = 0;
	if (!num_l)
		n_len++;
	while (num_l)
	{
		num_l /= 10;
		n_len++;
	}
	return (n_len);
}

void	ft_putnbr(long num_l)
{
	if (num_l < 10)
	{
		ft_putchar(num_l + '0');
		return ;
	}
	ft_putnbr(num_l / 10);
	ft_putchar((num_l % 10) + '0');
}

int	ft_printnbr(int num)
{
	int		p_len;
	long	num_l;

	p_len = 0;
	num_l = num;
	if (num_l < 0)
	{
		p_len += ft_putchar('-');
		num_l = -num_l;
	}
	ft_putnbr(num_l);
	p_len += ft_nbrlen(num_l);
	return (p_len);
}

int	ft_printunbr(unsigned int num)
{
	int		p_len;

	p_len = 0;
	ft_putnbr((long)num);
	p_len += ft_nbrlen((long)num);
	return (p_len);
}
