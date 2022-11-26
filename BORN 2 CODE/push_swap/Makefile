# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 12:37:50 by youngmch          #+#    #+#              #
#    Updated: 2022/11/26 21:22:35 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFlAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = push_swap.c init.c check_arg.c command.c command2.c utill.c utill2.c sort.c quick_sort.c
SRCS_BONUS = bonus.c check_arg.c command.c command2.c utill.c utill2.c sort.c quick_sort.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft
	@mv libft/libft.a .
	@$(CC) $(CFLAGS) $^ libft.a -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJS)
	@make fclean -C libft
	@$(RM) libft.a

fclean:clean
	@$(RM) $(NAME)

re: fclean all
