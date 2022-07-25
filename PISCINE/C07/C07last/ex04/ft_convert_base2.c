/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:38:03 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/07 15:13:34 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_gisu_base_to(long long int nbr,
		char *base_to, long long int len, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (nbr)
	{
		str[i] = base_to[nbr % len];
		nbr /= len;
		i++;
	}
	str[i] = 0;
}

void	ft_change(char *str, int nbr, int len, int i)
{
	char	temp;

	while (str[len])
		len++;
	if (nbr >= 0)
	{
		while (++i <= len / 2)
		{
			temp = str[i - 1];
			str[i - 1] = str[len - i];
			str[len - i] = temp;
		}
	}
	else if (nbr < 0)
	{
		i = 1;
		while (i <= len / 2)
		{
			temp = str[i];
			str[i] = str[len - i];
			str[len - i] = temp;
			i++;
		}
	}
}

char	*ft_putnbr_base(int nbr, char *base_to)
{
	long long int	k;
	long long int	len;
	char			*str;

	len = 0;
	while (base_to[len])
		len++;
	k = (long long int) nbr;
	str = (char *)malloc(sizeof(char) * 35);
	if (!str)
		return (NULL);
	if (nbr > 0)
		ft_gisu_base_to(k, base_to, len, str);
	else if (nbr < 0)
	{
		str[0] = '-';
		ft_gisu_base_to(-k, base_to, len, str);
	}
	else
	{
		str[0] = base_to[0];
		str[1] = 0;
	}
	ft_change(str, nbr, 0, 0);
	return (str);
}
