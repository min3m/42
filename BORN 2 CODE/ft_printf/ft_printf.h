/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:04:38 by youngmch          #+#    #+#             */
/*   Updated: 2022/09/29 21:58:49 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_type(va_list ap, char c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printnbr(int num);
void	ft_putnbr(long num_l);
int		ft_nbrlen(long num_l);
int		ft_printunbr(unsigned int num);
int		ft_printhex(unsigned int num, char c);
void	ft_puthex(unsigned int num, char c);
int		ft_hexlen(unsigned int num);
int		ft_printptr(void *ptr);
void	ft_putptr(unsigned long num);
int		ft_ptrlen(unsigned long num);

#endif
