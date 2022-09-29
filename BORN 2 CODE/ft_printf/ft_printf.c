/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:01:37 by youngmch          #+#    #+#             */
/*   Updated: 2022/09/29 21:49:51 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_type(va_list ap, char c)
{
	int	p_len;

	p_len = 0;
	if (c == 'c')
		p_len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		p_len += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		p_len += ft_printnbr(va_arg(ap, int));
	else if (c == 'u')
		p_len += ft_printunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		p_len += ft_printhex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		p_len += ft_printptr(va_arg(ap, void *));
	else if (c == '%')
		p_len += ft_putchar('%');
	return (p_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		p_len;

	i = 0;
	p_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			p_len += ft_type(ap, format[i]);
		}
		else
			p_len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (p_len);
}
