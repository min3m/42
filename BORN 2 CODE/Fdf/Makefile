# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:59:27 by youngmch          #+#    #+#              #
#    Updated: 2022/11/15 12:39:39 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf
CC = cc
CFlAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = fdf.c map_parsing.c machine_init.c drawing_func1.c drawing_func2.c \
matrix1.c matrix2.c matrix3.c utill.c key_hook.c camera.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		@make -C libft
		@mv libft/libft.a .
		@make -C mlx_mms
		@cp mlx_mms/libmlx.dylib .
		@$(CC) $(CFLAGS) $^ libft.a -Lmlx_mms -lmlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore -o $@
		@mkdir objs
		@mv *.o ./objs/
		@mv libft.a ./objs/

%.o: %.c
		@$(CC) $(CFLAGS) -Imlx_mms -c $^ -o $@

clean:
		@$(RM) ./objs
		@$(RM) ./objs/*.o
		@make fclean -C libft
		@make clean -C mlx_mms

fclean: clean
		@$(RM) $(NAME)
		@$(RM) libmlx.dylib

re: fclean all
