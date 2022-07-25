/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:44:26 by youngmch          #+#    #+#             */
/*   Updated: 2022/06/05 23:50:17 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct {
	char *num;
	char *blank;
	char *mean;
}Rush;

int	main(int argc, char **agrv)
{
	int		size;
	FILE	*fp;
	Rush	*dict;

	if (argc == 1)
	{
		fp = fopen("number.dict", "r");

		fread(dict);

		fclose(fp);
	}
	if (argc == 2)
	{
		fp = fopen("number.dict", "r");

		fread(dict);

		fclose(fp);
	}
	return (0);
}
