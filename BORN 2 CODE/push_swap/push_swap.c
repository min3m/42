/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:26:39 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/23 21:38:22 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_init(char **argv)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**arr;

	i = 1;
	str = ft_strdup("");
	while (argv[i])
	{
		tmp = str;
		str = ft_strjoin(str, argv[i]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	if (!arr)
		exit(EXIT_FAILURE);
	return (arr);
}

int main(int argc, char **argv)
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
	}
	return (0);
}
// 		s_(stack, 'a');
// 		p_(stack, 'b');
// 		r_(stack, 'a');
// 		rr_(stack, 'a');
// 		p_(stack, 'b');
// 		rr_(stack, 'b');
// 		rr_(stack, 'b');
// 		p_(stack, 'a');
// 		p_(stack, 'b');
// 		p_(stack, 'b');
// 		p_(stack, 'b');
// 		r_(stack, 'a');
// 		rr_(stack, 'b');
// for (t_list *curr = stack->stack_a ; curr != NULL ; curr=curr->next)
// 			printf("%d->",curr->data.value);
// 		printf("\n");
// 		for (t_list *curr = stack->stack_b ; curr != NULL ; curr=curr->next)
// 			printf("%d->",curr->data.value);
// 		printf("\n");
