/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:27 by youngmch          #+#    #+#             */
/*   Updated: 2022/09/29 21:55:48 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	h_len;

	h_len = 0;
	if (!num)
		h_len++;
	while (num)
	{
		num /= 16;
		h_len++;
	}
	return (h_len);
}

void	ft_puthex(unsigned int num, char c)
{
	if (num < 16)
	{
		if (c == 'x')
			ft_putchar("0123456789abcdef"[num % 16]);
		else
			ft_putchar("0123456789ABCDEF"[num % 16]);
		return ;
	}
	ft_puthex(num / 16, c);
	if (c == 'x')
		ft_putchar("0123456789abcdef"[num % 16]);
	else
		ft_putchar("0123456789ABCDEF"[num % 16]);
}

int	ft_printhex(unsigned int num, char c)
{
	int	p_len;

	p_len = 0;
	ft_puthex(num, c);
	p_len += ft_hexlen(num);
	return (p_len);
}
