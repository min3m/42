/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:54:51 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/04 20:29:34 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *base, int len)
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

int	ft_gisu(char *str, char *base, int len_base, int len_str)
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

int	ft_atoi_base(char *str, char *base)
{
	int	len_base;
	int	len_str;
	int	result;

	len_str = 0;
	len_base = 0;
	result = 0;
	while (str[len_str])
		len_str++;
	while (base[len_base])
		len_base++;
	if (check(base, len_base))
		result = ft_gisu(str, base, len_base, len_str);
	else
		return (0);
	return (result);
}
