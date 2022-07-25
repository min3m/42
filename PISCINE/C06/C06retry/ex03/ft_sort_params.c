/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:06:16 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/08 22:11:20 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	swap(char **str, char **str1)
{
	char	*temp;

	temp = *str;
	*str = *str1;
	*str1 = temp;
}

int	ft_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i] && str1[i])
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (str[i] - str1[i]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;
	char	*str1;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			j = 1;
			while (j < argc - 1)
			{
				str = argv[j];
				str1 = argv[j + 1];
				if (ft_strcmp(str, str1) > 0)
					swap(&argv[j], &argv[j + 1]);
				j++;
			}
			i++;
		}
		ft_print(argc, argv);
	}
	return (0);
}
