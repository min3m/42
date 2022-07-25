/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:08:53 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/02 20:23:30 by youngmch         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	long long int	num;

	num = (long long int) nb;
	while (!ft_is_prime(num))
		num++;
	return ((int)num);
}
