/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:16:19 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/30 18:28:04 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	to_find_len(char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
		i++;
	return (i);
}

int	check(char *to_find)
{
	if (to_find[0] == 0)
		return (1);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;
	int	l;
	int	c;

	i = 0;
	k = 0;
	c = 1;
	if (check(to_find))
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[k])
		{
			l = i;
			while (str[++l] == to_find[++k] && str[l] != 0 && to_find[k] != 0)
				c++;
			if (to_find_len(to_find) == c)
				return (&str[i]);
			k = 0;
			c = 1;
		}
		i++;
	}
	return (0);
}
