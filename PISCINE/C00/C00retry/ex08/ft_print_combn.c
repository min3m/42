/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:02:08 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/25 15:47:50 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *arr, int n)
{
	write(1, arr, n);
	if (arr[0] != ('9' - n + 1))
		write(1, ", ", 2);
}

void	ft_make(char *arr, int n)
{	
	int	i;

	i = 0;
	ft_print(arr, n);
	arr[n - 1]++;
	while (i < n)
	{
		if (arr[i] > '9')
		{
			arr[i] = arr[i - 1] + 1;
			arr[i - 1]++;
			i = -1;
		}
		if (arr[n - 2] == arr[n - 1])
			arr[n - 1]++;
		i++;
	}
	if (arr[0] == ('9' - n + 1))
	{
		ft_print(arr, n);
		return ;
	}
	ft_make(arr, n);
}

void	ft_print_combn(int n)
{
	char	b[11];
	int		i;

	i = 0;
	if (n <= 0 && n >= 10)
		return ;
	while (i < n)
	{
		b[i] = i + '0';
		i++;
	}
	ft_make(b, n);
}
