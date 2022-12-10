# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 17:20:05 by youngmch          #+#    #+#              #
#    Updated: 2022/12/04 17:22:19 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFlAGS = -Wall -Wextra -Werror
SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS_RESULT)
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
	@$(RM) pipex

re: fclean all

