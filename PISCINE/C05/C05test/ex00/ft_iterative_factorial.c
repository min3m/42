/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:35:48 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/02 20:21:04 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	facto;

	facto = nb;
	if (nb < 0)
		return (0);
	else if (nb > 0)
	{
		while (--nb > 0)
			facto *= nb;
	}
	else
		return (1);
	return (facto);
}
