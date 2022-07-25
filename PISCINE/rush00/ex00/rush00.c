/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:55:36 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/24 12:44:41 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	check(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return (0);
	}
	return (1);
}

void	print(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i == x && j == y))
		ft_putchar('o');
	else if ((i == 1 && j == y) || (i == x && j == 1))
		ft_putchar('o');
	else if (j == 1 || j == y)
		ft_putchar('-');
	else if (i == 1 || i == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (check(x, y))
	{
		while (j <= y)
		{
			i = 1;
			while (i <= x)
			{
				print(x, y, i, j);
				i++;
			}
			ft_putchar('\n');
			j++;
		}
	}
}
