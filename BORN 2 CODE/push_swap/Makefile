# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 12:37:50 by youngmch          #+#    #+#              #
#    Updated: 2022/11/16 21:59:14 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFlAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = push_swap.c check_argu.c stack_init.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)
	@make clean

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
