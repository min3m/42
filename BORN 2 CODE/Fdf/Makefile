# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 20:06:28 by youngmch          #+#    #+#              #
#    Updated: 2022/10/07 17:43:53 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFlAGS = -Wall -Wextra -Werror -g
SRCS = fdf.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
		@ar rcs $(NAME) $^
		@make -C mlx_mms
		@cp mlx_mms/libmlx.dylib .
		@${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
		@$(CC) $(CFLAGS) $^ -Lmlx_mms -lmlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore -o $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) libmlx.dylib

re: fclean all
