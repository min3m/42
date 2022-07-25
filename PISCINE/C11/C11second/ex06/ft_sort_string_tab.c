/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:44:47 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/09 00:36:04 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **str, char **str1)
{
	char	*temp;

	temp = *str;
	*str = *str1;
	*str1 = temp;
}

int	ft_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i] && str1[i])
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (str[i] - str1[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*str;
	char	*str1;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j] && tab[j + 1] != 0)
		{
			str = tab[j];
			str1 = tab[j + 1];
			if (ft_strcmp(str, str1) > 0)
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
