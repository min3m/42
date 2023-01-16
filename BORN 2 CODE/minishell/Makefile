# ---- NAME ---- #

NAME = minishell

FT = ./libft/libft.a
FTCC = -L./libft -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror $(DB)
DB = -g3
FA = -fsanitize=address
AR = ar
ARFLAG = ruc
RM = rm -f

# READLINE_LIB = -lreadline -L/usr/local/opt/readline/lib
# READLINE_INC = -I/usr/local/opt/readline/include

READLINE_LIB = -lreadline -L$(shell brew --prefix readline)/lib
READLINE_INC = -I/$(shell brew --prefix readline)/include

object_dir = ./objects

# ---- escape ---- #

DELINE = \033[K
CURSUP = \033[A

RESET = \033[0m
RESTINT = \033[22m

BOLD = \033[1m

MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m

# ---- Mandatory ---- #

sources1 :=

sources1 += ft_exit/error_parse.c
sources1 += ft_exit/error_cmd.c
sources1 += ft_exit/error_exe.c
sources1 += ft_exit/error_prompt.c
sources1 += ft_exit/error_builtin.c

sources1 += parse/parse.c
sources1 += parse/parse_node.c
sources1 += parse/ft_strndup.c
sources1 += parse/separate_quote.c
sources1 += parse/separate_quote_try.c
sources1 += parse/trans_dollar.c
sources1 += parse/split_dollar.c
sources1 += parse/separate_space.c
sources1 += parse/separate_pipe.c
sources1 += parse/separate_red.c
sources1 += parse/del_empty.c
sources1 += parse/change_able.c
sources1 += parse/union_able.c
sources1 += parse/del_space.c
sources1 += parse/check_cmd_error.c

sources1 += exe/cmd_node.c
sources1 += exe/make_cmd_list.c
sources1 += exe/make_cmd.c
sources1 += exe/make_error_cmd.c
sources1 += exe/set_cmd.c
sources1 += exe/execute.c
sources1 += exe/execute_func.c
sources1 += exe/initcmd.c
sources1 += exe/make_heredoc.c
sources1 += exe/open_heredoc.c
sources1 += exe/make_heredoc_utils.c
sources1 += exe/here_doc_dollar.c
sources1 += exe/here_doc_dollar_utils.c
sources1 += exe/utils.c
sources1 += exe/parent_main.c
sources1 += exe/child_main.c
sources1 += exe/exec_cmd.c
sources1 += exe/exec_utils.c
sources1 += exe/is_builtin.c
sources1 += exe/exe_sig_handle.c
sources1 += exe/ft_split_non.c
sources1 += exe/make_env.c

sources1 += prompt/minishell.c
sources1 += prompt/prompt.c
sources1 += prompt/sig_handler.c
sources1 += prompt/sig_handler2.c
sources1 += prompt/env_list.c
sources1 += prompt/utils.c
sources1 += prompt/utils2.c

sources1 += builtin/echo.c
sources1 += builtin/cd.c
sources1 += builtin/pwd.c
sources1 += builtin/environ.c
sources1 += builtin/environ_util.c
sources1 += builtin/environ_util2.c
sources1 += builtin/exit.c

# ---- Bonus ---- #

sources2 :=

sources2 +=

# ---- Elements ---- #

all_sources = $(sources1) $(sources2)

objects1 = $(sources1:.c=.o)
objects2 = $(sources2:.c=.o)
all_objects = $(objects1) $(objects2)

define objects_goal
$(addprefix $(object_dir)/, $(call $(if $(filter bonus, $(MAKECMDGOALS)), all_objects, objects1)))
endef

define react
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

# ---- Command ---- #

.PHONY : clean fclean re all bonus

all : $(NAME)

$(NAME) : $(objects_goal) $(FT)
	@$(CC) $(CFLAGS) $(READLINE_INC) $(READLINE_LIB) -o $@ $(objects_goal) $(FTCC)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

bonus : $(NAME)

$(object_dir)/%.o : %.c
	@#mkdir -p $(object_dir)
	@mkdir -p $(object_dir)/$(dir $^)
	@$(CC) $(CFLAGS) $(READLINE_INC) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

$(FT) :
	@make -C ./libft all

clean :
	@$(RM) $(all_objects)
	@rm -rf $(object_dir)
	@make -C ./libft clean
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)
