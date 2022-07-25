/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:27:42 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/30 12:32:35 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	int				j;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)str;
	while (str2[i])
	{
		if (str2[i] < 32 || str2[i] >= 127)
		{
			j = str2[i];
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[j / 16], 1);
			write(1, &"0123456789abcdef"[j % 16], 1);
		}
		else
			write(1, &str2[i], 1);
		i++;
	}
}
