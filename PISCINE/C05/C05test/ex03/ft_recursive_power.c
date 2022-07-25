/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:43:06 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/30 23:48:24 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	num;

	num = 1;
	if (power < 0)
		return (0);
	if (nb == 0)
	{
		if (power == 0)
			return (1);
		else
			return (0);
	}
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
