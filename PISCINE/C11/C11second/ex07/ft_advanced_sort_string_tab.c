/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:19:01 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/09 00:20:16 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **str, char **str1)
{
	char	*temp;

	temp = *str;
	*str = *str1;
	*str1 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(str, str1) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
