/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:54:06 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/30 22:21:48 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int nb)
{
	if (nb <= 0)
		return ;
	ft_print(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			ft_print(-nb);
		}
	}
	else if (nb > 0)
		ft_print(nb);
	else
		write(1, "0", 1);
}
