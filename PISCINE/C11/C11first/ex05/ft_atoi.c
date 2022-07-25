/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:26:01 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/09 21:55:53 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	long long int	result;
	long long int	sign;

	result = 0;
	sign = 1;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32
			|| *str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
		}
		else
			break ;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return ((int)(result * sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
