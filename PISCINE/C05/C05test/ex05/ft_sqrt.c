/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:28:20 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/02 21:02:28 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_recursive(int nb, long long int *point)
{
	if ((*point) * (*point) == nb)
		return ;
	else if ((*point) * (*point) > nb)
		return ;
	*point += 1;
	ft_recursive(nb, point);
	return ;
}

int	ft_sqrt(int nb)
{
	int				num;
	long long int	point;

	if (nb < 0)
		return (0);
	num = nb;
	point = 1;
	ft_recursive(num, &point);
	if (point * point == nb)
		return ((int)point);
	else
		return (0);
}
