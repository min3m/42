/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:26:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/26 21:45:59 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**arr;
	t_stack	*stack;

	i = -1;
	if (argc >= 2)
	{
		while (argv[++i])
		{
			if (!(ft_strncmp(argv[i], "", ft_strlen(argv[i]))))
				exit(ft_putendl_fd("Error", 1));
		}
		arr = arg_init(argv);
		check_arg(arr);
		stack = stack_init(arr);
		sort_arg(stack);
		exit_push_swap(stack, EXIT_SUCCESS);
	}
	return (0);
}
