# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 17:20:05 by youngmch          #+#    #+#              #
#    Updated: 2022/12/12 20:35:50 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFlAGS = -Wall -Wextra -Werror
SRCS = pipex.c pipex_utils.c
SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -rf

ifdef BONUS
		OBJS_RESULT = $(OBJS_BONUS)
else
		OBJS_RESULT = $(OBJS)
endif

all: $(NAME)

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
	@$(RM) pipex

re: fclean all

