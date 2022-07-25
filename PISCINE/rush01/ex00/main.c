/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:45:08 by jinam             #+#    #+#             */
/*   Updated: 2022/05/29 19:33:27 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nb);
void	ft_putchar(char n);

int	validation(char *str)
{
	int	count;
	int	res;

	count = 0;
	res = 1;
	while (*str != '\0')
	{
		if ('1' <= *str && *str <= '4')
			count ++;
		else
		{
			if (*str != ' ')
				return (0);
		}
		str ++;
	}
	if (count != 16)
		res = 0;
	return (res);
}

int	*conv_argv(char *str)
{
	int	index;
	int	*res;

	res = (int *) malloc(sizeof(int *) * 16);
	index = 0;
	while (*str != '\0')
	{
		if (*str != ' ' )
		{
			res[index] = *str - '0';
			index ++;
		}
		str ++;
	}
	return (res);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	print_arr(void **arg_int)
{
	int	(*ap)[4];
	int	index_1;
	int	index_2;

	ap = (int (*)[4]) arg_int;
	index_1 = 0;
	while (index_1 < 4)
	{
		index_2 = 0;
		while (index_2 < 4)
		{
			ft_putnbr(ap[index_1][index_2]);
			if (index_2 != 3)
				write(1, ", ", 2);
			index_2 ++;
		}
		index_1 ++;
		ft_putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	int	*arg_int;
	int	arg_validation;
	int	(*ap)[4];

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	arg_validation = validation(argv[1]);
	if (!arg_validation)
	{
		print_error();
		return (0);
	}
	arg_int = conv_argv(argv[1]);
	ap = (int (*)[4]) arg_int;
	print_arr((void **)arg_int);
	return (0);
}
