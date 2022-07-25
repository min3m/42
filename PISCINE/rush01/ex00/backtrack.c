/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:10:32 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/29 22:21:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_len(char *view)
{
	int	i;

	i = 0;
	while (view[i])
		i++;
	return (i);
}

void	ft_memset(char **sky, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while(j < n)
		{
			sky[i][j] = '0';
			j++;
		}
		sky[i][j] = 0;
		i++;
	}
}

void	ft_scraper(char **sky, char *input, int n)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	check1[10][10];
	char	incheck[40];

	i = 0;
	j = 0;
	len = n / 4;
	while (i < n)
	{
		incheck[i] = input[i];
		if (input[i] == '1' && i < (n / 4))
			sky[0][i % 4] = '4';
		else if (input[i] == '1' && (i >= (n / 4) && i < (n / 4) * 2))
			sky[(n / 4) - 1][i % 4] = '4';
		else if (input[i] == '1' && (i >= (n / 4) * 2 && i < (n / 4) * 3))
			sky[i % 4][0] = '4';
		else if (input[i] == '1' && (i >= (n / 4) * 3 && i < n))
			sky[i % 4][(n / 4) - 1] = '4';
		j = 0;
		while (j < n)
		{
			check1[i][j] = sky[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < n / 4)
	{
		j = 0;
		while (j < n / 4)
		{
			if (check1[i][j] == '0')
			{
				k = 1;
				while (k <= n / 4)
				{
					chekc1[i][j] = '0' + k;
					k++;
				}
				if (check(check1, incheck, i ,j ,k, len))
				{
				}
				return (0);
			}
		}
	}
}

int	check(char **sky, char *input, int x, int y, int z, int len)
{
	int	i;
	int k;
	int l;
	char num;

	i = 0;
	k = 0;
	l = 0;
	num = sky[x][y];
	while (i < len)
	{
		if (num < sky[x][i])
		{
			num = sky[x][i];	
			k++;
		}
		i++;
	}
	i = 0;
	if (x > len)
	{
		while (i < len)
		{
			if (num < sky[i][y])
			{
				num = sky[i][y];
				l++;
			}
			i++;
		}
	}
	return 
}
