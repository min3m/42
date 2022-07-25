/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:36:02 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/02 20:21:01 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *list)
{
	int		i;
	char	str;

	i = 0;
	while (i < 10)
	{
		str = (char)list[i] + '0';
		write(1, &str, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int abs)
{
	if (abs < 0)
		return (-abs);
	else
		return (abs);
}

int	ft_check(int depth, int i, int *list)
{
	int	j;

	j = 0;
	while (j < depth)
	{
		if (list[j] == i || ft_abs(list[j] - i) == ft_abs(depth - j))
			return (0);
		j++;
	}
	return (1);
}

void	ft_queenback(int depth, int *list, int *result)
{
	int	i;
	int	flag;

	if (depth == 10)
	{
		ft_print(list);
		*result += 1;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		flag = 1;
		flag = ft_check(depth, i, list);
		if (flag)
		{
			list[depth] = i;
			ft_queenback(depth + 1, list, result);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	list[11];
	int	result;

	i = 0;
	result = 0;
	while (i < 11)
	{
		list[i] = 0;
		i++;
	}
	result = 0;
	ft_queenback(0, list, &result);
	return (result);
}
