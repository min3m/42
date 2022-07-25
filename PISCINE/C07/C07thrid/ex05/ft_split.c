/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:06:17 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/07 16:29:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_cmp(char str, char *charset)
{
	int	i;

	i = 0;
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str && word_cmp(*str, charset))
			return (len);
		len++;
		str++;
	}
	return (len);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	while (*str)
	{	
		while (*str && word_cmp(*str, charset))
			str++;
		if (!(*str))
			break ;
		len = word_len(str, charset);
		str += len;
		count++;
	}
	return (count);
}

void	ft_strncpy(char **strs, char *str, int len, int index)
{
	int	i;

	i = 0;
	while (i < len)
	{
		strs[index][i] = *str;
		i++;
		str++;
	}
	strs[index][i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		count;
	int		len;
	int		i;

	i = 0;
	count = word_count(str, charset);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!(strs))
		return (0);
	strs[count] = 0;
	while (*str)
	{
		while (*str && word_cmp(*str, charset))
			str++;
		if (!(*str))
			break ;
		len = word_len(str, charset);
		strs[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!(strs[i]))
			return (0);
		ft_strncpy(strs, str, len, i++);
		str += len;
	}
	return (strs);
}
