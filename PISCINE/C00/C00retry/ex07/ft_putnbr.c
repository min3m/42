/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:14:31 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/07 20:09:30 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_plus(int nb)
{
	char	i;

	i = nb % 10 + '0';
	if (nb > 0)
	{
		ft_plus(nb / 10);
		write(1, &i, 1);
	}
	else
		return ;
}

void	ft_putnbr(int nb)
{
	if (nb > 0)
		ft_plus(nb);
	else if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
		}
		else
		{
			write(1, "-", 1);
			ft_plus(-nb);
		}
	}
	else
		write(1, "0", 1);
}
