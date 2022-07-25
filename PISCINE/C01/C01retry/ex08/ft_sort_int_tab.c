/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:13:51 by youngmch          #+#    #+#             */
/*   Updated: 2022/05/24 19:27:31 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int a, int b)
{
	int	temp;

	temp = 0;
	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

void	ft_qsort(int *tab, int left, int right)
{
	int	r;
	int	l;
	int	pivot;

	if (left >= right)
		return ;
	l = left + 1;
	r = right;
	pivot = tab[left];
	while (l <= r)
	{
		while (l <= right && pivot >= tab[l])
			l++;
		while (r > left && pivot <= tab[r])
			r--;
		if (l > r)
			swap(tab, r, left);
		else
			swap(tab, l, r);
	}
	ft_qsort(tab, left, r - 1);
	ft_qsort(tab, r + 1, right);
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_qsort(tab, 0, size - 1);
}
