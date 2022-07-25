/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:58:05 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/09 19:42:11 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (length == 0 || length == 1 || length == 2)
		return (1);
	while (i < length - 1)
	{
		if (check == 0 && f(tab[i], tab[i + 1]) != 0)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				check = 1;
			else if (f(tab[i], tab[i + 1]) < 0)
				check = -1;
		}
		else if (check > 0 && f(tab[i], tab[i + 1]) < 0)
			return (0);
		else if (check < 0 && f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
