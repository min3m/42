# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 12:37:50 by youngmch          #+#    #+#              #
#    Updated: 2022/11/27 18:17:10 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFlAGS = -Wall -Wextra -Werror
SRCS = push_swap.c init.c check_arg.c command.c command2.c utill.c utill2.c sort.c quick_sort.c
SRCS_BONUS = bonus.c init.c bonus_check_arg.c check_arg.c bonus_cmd.c utill.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
		NAME = checker
else
		NAME = push_swap
endif

ifdef BONUS
		OBJS_RESULT = $(OBJS_BONUS)
else
		OBJS_RESULT = $(OBJS)
endif

RM = rm -rf

all: $(NAME)
	@make clean

$(NAME): $(OBJS_RESULT)
	@make bonus -C libft
	@mv libft/libft.a .
	@$(CC) $(CFLAGS) $^ libft.a -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

bonus:
	@make BONUS=1

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make fclean -C libft
	@$(RM) libft.a

fclean:clean
	@$(RM) checker
	@$(RM) push_swap

re: fclean all
