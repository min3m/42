/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:26:51 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/27 16:28:06 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_pivot{
	int	s;
	int	b;
}				t_pivot;

typedef struct s_count{
	int	ra;
	int	pb;
	int	pa;
	int	rb;
}				t_count;

typedef struct s_stack{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stack;

/* ARGUMENT IN */
char	**arg_init(char **argv);
/* CHECK ARGUMENT */
void	free_arr(char **arr);
void	check_arg(char **argv);
void	check_sorted(char **arr);
/* STACK INIT */
t_stack	*stack_init(char **arr);
/* COMMAND */
void	s_(t_stack *stack, char c);
void	p_(t_stack *stack, char c);
void	r_(t_stack *stack, char c);
void	rr_(t_stack *stack, char c);
void	rr(t_stack *stack);
void	rrr(t_stack *stack);
/* SORT */
void	sort_arg(t_stack *stack);
void	sort_two(t_stack *stack, int num, char c);
void	sort_three_a(t_stack *stack, int count, int size);
void	sort_three_b(t_stack *stack, int count);
void	sort_five(t_stack *stack, int count, int min);
/* QUICK SORT */
void	quick_sort(t_stack *stack);
void	a_to_b(t_stack *stack, int num);
void	b_to_a(t_stack *stack, int num);
t_count	sort_index_a(t_stack *stack, int index, t_count count, t_pivot pivot);
t_count	sort_index_b(t_stack *stack, int index, t_count count, t_pivot pivot);
/* UTILL */
void	exit_push_swap(t_stack *stack, int result);
int		ft_push(t_list **stack, t_list *new, int flag);
t_list	*ft_pop(t_list **stack, int index);
/* UTILL2 */
void	set_c(t_count *c);
t_pivot	set_p(t_list *stack, int count);
int		ft_find_max(t_list *stack, int count);
int		ft_find_min(t_list *stack, int count);
void	re_wind(t_stack *stack, int ra, int rb);
/* BONUS */
void	run_checker(t_stack *stack);
void	do_cmd(t_stack *stack, char *cmd);
void	bonus_check_arg(char **arr);
/* BONUS CMD */
void	bonus_s_(t_stack *stack, char c);
void	bonus_p_(t_stack *stack, char c);
void	bonus_r_(t_stack *stack, char c);
void	bonus_rr_(t_stack *stack, char c);
void	bonus_ss(t_stack *stack);
void	bonus_rr(t_stack *stack);
void	bonus_rrr(t_stack *stack);

#endif
