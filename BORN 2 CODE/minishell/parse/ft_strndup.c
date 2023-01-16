/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:11:37 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:39 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
