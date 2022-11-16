/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:26:51 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/16 21:51:45 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stack;

/* ARGUMENT IN */
char	**argu_init(char **argv);
/* CHECK ARGUMENT */
void	free_arr(char **arr);
void	check_argu(int argc, char **argv);
void	check_sorted(int argc, char **arr);
/* STACK INIT */
t_stack	*stack_init(char **arr);

#endif
