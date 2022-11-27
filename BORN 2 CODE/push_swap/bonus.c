/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:11:59 by youngmch          #+#    #+#             */
/*   Updated: 2022/11/27 16:32:29 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_bonus(t_stack *stack)
{
	t_list	*curr;

	if (ft_lstsize(stack->stack_b))
		return (0);
	curr = stack->stack_a;
	while (curr->next)
	{
		if (curr->data.index > curr->next->data.index)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	do_cmd(t_stack *stack, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		bonus_s_(stack, 'a');
	else if (!ft_strcmp(cmd, "sb\n"))
		bonus_s_(stack, 'b');
	else if (!ft_strcmp(cmd, "ss\n"))
		bonus_s_(stack, 's');
	else if (!ft_strcmp(cmd, "pa\n"))
		bonus_p_(stack, 'a');
	else if (!ft_strcmp(cmd, "pb\n"))
		bonus_p_(stack, 'b');
	else if (!ft_strcmp(cmd, "ra\n"))
		bonus_r_(stack, 'a');
	else if (!ft_strcmp(cmd, "rb\n"))
		bonus_r_(stack, 'b');
	else if (!ft_strcmp(cmd, "rr\n"))
		bonus_r_(stack, 'r');
	else if (!ft_strcmp(cmd, "rra\n"))
		bonus_rr_(stack, 'a');
	else if (!ft_strcmp(cmd, "rrb\n"))
		bonus_rr_(stack, 'b');
	else if (!ft_strcmp(cmd, "rrr\n"))
		bonus_rr_(stack, 'r');
	else
		exit_push_swap(stack, ft_putendl_fd("Error", 1));
}

void	run_checker(t_stack *stack)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		do_cmd(stack, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	if (sorted_bonus(stack))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

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
		bonus_check_arg(arr);
		stack = stack_init(arr);
		run_checker(stack);
		exit_push_swap(stack, EXIT_SUCCESS);
	}
	return (0);
}
