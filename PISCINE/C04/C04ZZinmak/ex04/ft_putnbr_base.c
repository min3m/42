/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:17:27 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/04 20:26:32 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *base, long long int len)
{
	long long int	i;
	long long int	j;

	i = 0;
	j = 0;
	if (len <= 1)
		return (0);
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_gisu(long long int nbr, char *base, long long int len)
{
	if (nbr == 0)
		return ;
	ft_gisu(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long int	k;
	long long int	len;

	len = 0;
	while (base[len])
		len++;
	k = (long long int) nbr;
	if (check(base, len))
	{
		if (nbr > 0)
			ft_gisu(k, base, len);
		else if (nbr < 0)
		{
			write(1, "-", 1);
			ft_gisu(-k, base, len);
		}
		else
			write(1, &base[0], 1);
	}
}
