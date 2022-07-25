/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:56:12 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/30 13:24:05 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_len(src);
	if (size == 0)
		return (len);
	while (i < size - 1 && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
