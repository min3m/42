/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:35:45 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/10 00:59:21 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
int		ft_op(int check, int a, int b);
int		check_op(char *op);
void	ft_print_num(int num);

int	main(int argc, char **argv)
{
	int	num1;
	int	num2;
	int	result;

	if (argc == 4)
	{	
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		if (!check_op(argv[2]))
			write(1, "0", 1);
		else if (check_op(argv[2]) == 4 && num2 == 0)
			write(1, "Stop : division by zero", 23);
		else if (check_op(argv[2]) == 5 && num2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else
		{
			result = ft_op(check_op(argv[2]), num1, num2);
			if (result == 0)
				write(1, "0", 1);
			ft_print_num(result);
		}
		write(1, "\n", 1);
	}
	return (0);
}
