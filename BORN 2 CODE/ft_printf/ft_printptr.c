/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:24 by youngmch          #+#    #+#             */
/*   Updated: 2022/09/29 21:51:53 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long num)
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

void	ft_putptr(unsigned long num)
{
	if (num < 16)
	{
		ft_putchar("0123456789abcdef"[num % 16]);
		return ;
	}
	ft_putptr(num / 16);
	ft_putchar("0123456789abcdef"[num % 16]);
}

int	ft_printptr(void *ptr)
{
	int				p_len;
	unsigned long	num;

	p_len = 0;
	num = (unsigned long)ptr;
	p_len += ft_putstr("0x");
	ft_putptr(num);
	p_len += ft_ptrlen(num);
	return (p_len);
}
