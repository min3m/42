/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:11:14 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/31 20:38:25 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long int	prime;

	prime = 2;
	if (nb <= 1)
		return (0);
	while (prime * prime <= nb)
	{
		if (nb % prime == 0)
			return (0);
		prime++;
	}
	return (1);
}
