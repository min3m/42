/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:26:36 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/09 21:57:29 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_op(int check, int a, int b)
{
	if (check == 1)
		return (a + b);
	if (check == 2)
		return (a - b);
	if (check == 3)
		return (a * b);
	if (check == 4)
		return (a / b);
	if (check == 5)
		return (a % b);
	return (0);
}

int	check_op(char *op)
{
	if (*op == '+' && *(op + 1) == 0)
		return (1);
	else if (*op == '-' && *(op + 1) == 0)
		return (2);
	else if (*op == '*' && *(op + 1) == 0)
		return (3);
	else if (*op == '/' && *(op + 1) == 0)
		return (4);
	else if (*op == '%' && *(op + 1) == 0)
		return (5);
	return (0);
}
