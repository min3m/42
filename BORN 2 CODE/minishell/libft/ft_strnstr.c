/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:09 by dongyoki          #+#    #+#             */
/*   Updated: 2022/11/12 14:37:13 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	repeat;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(haystack);
	if (len1 < len)
		len = len1;
	len2 = ft_strlen(needle);
	if (len < len2)
		return (0);
	repeat = len - len2 + 1;
	if (len2 == 0)
		return ((char *)haystack);
	i = 0;
	while (i < repeat)
	{
		if (ft_strncmp((char *)haystack + i, (char *)needle, len2) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
