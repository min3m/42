/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:45:16 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/30 13:26:44 by youngmch         ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_len(src);
	while (i < n)
	{
		if (i < len)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}
