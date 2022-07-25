/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:45:01 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/07 15:11:28 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_gisu_base_to(long long int nbr, char *base_to,
			long long int len, char *str);
void	ft_change(char *str, int nbr, int len, int i);
char	*ft_putnbr_base(int nbr, char *base_to);

int	check_base(char *base, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (len <= 1)
		return (0);
	while (i < len)
	{
		if ((base[i] == '-' || base[i] == '+')
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

int	ft_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		*i += 1;
	while ((str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

int	ft_gisu_base_from(char *str, char *base, int len_base, int len_str)
{
	int				i;
	int				j;
	long long int	sign;
	long long int	result;

	i = 0;
	result = 0;
	sign = (long long int)ft_sign(str, &i);
	while (i < len_str)
	{
		result *= (long long int)len_base;
		j = -1;
		while (base[++j])
		{
			if (str[i] == base[j])
			{
				result += (long long int)j;
				break ;
			}
		}
		if (j == len_base)
			return ((int)(result * sign / (long long int)len_base));
		i++;
	}
	return ((int)(result * sign));
}

int	ft_atoi_base(char *str, char *base_from)
{
	int	len_base;
	int	len_str;
	int	result;

	len_str = 0;
	len_base = 0;
	result = 0;
	while (str[len_str])
		len_str++;
	while (base_from[len_base])
		len_base++;
	result = ft_gisu_base_from(str, base_from, len_base, len_str);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		len_from;
	int		len_to;
	char	*str;

	len_from = 0;
	len_to = 0;
	while (base_from[len_from])
		len_from++;
	while (base_to[len_to])
		len_to++;
	if (!(check_base(base_from, len_from)) || !(check_base(base_to, len_to)))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	str = (char *)malloc(sizeof(char) * 35);
	if (!str)
		return (0);
	str = ft_putnbr_base(num, base_to);
	return (str);
}
