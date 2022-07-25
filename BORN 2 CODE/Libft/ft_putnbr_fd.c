/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:49:55 by youngmch          #+#    #+#             */
/*   Updated: 2022/07/19 13:22:39 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive_fd(long long num, int fd)
{
	if (num == 0)
		return ;
	ft_recursive_fd(num / 10, fd);
	write(fd, &"0123456789"[num % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = -(long long)n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else
		num = n;
	ft_recursive_fd(num, fd);
}
