NAME = libftprintf.a
CC = cc
CFlAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printnbr.c ft_printhex.c ft_printptr.c
BSRCS =
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
RM = rm -f
ifdef WITH_BONUS
		OBJ_RESULT = ${OBJS} ${BOBJS}
else
		OBJ_RESULT = ${OBJS}
endif

all: $(NAME)
$(NAME): $(OBJ_RESULT)
		ar rcs $(NAME) $^

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

bonus:
		make WITH_BONUS=1 all

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
