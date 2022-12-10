/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:46:58 by youngmch          #+#    #+#             */
/*   Updated: 2022/07/18 20:19:19 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_change(long long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	ft_nlen(int n)
{
	int			i;
	long long	num;

	i = 0;
	num = ft_change(n);
	if (n < 0 || n == 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	ft_swap(char *str, int len)
{
	char	temp;
	int		i;

	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 0;
	str = (char *)malloc(sizeof(char) * (ft_nlen(n) + 1));
	if (!str)
		return (0);
	if (n < 0)
		sign = 1;
	num = ft_change((long long)n);
	if (num == 0)
		str[i++] = '0';
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	if (sign == 1)
		str[i++] = '-';
	str[i] = 0;
	ft_swap(str, i);
	return (str);
}
