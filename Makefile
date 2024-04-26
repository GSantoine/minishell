#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := minishell
CC        := clang
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/redirections/redirect.c \
                          src/redirections/check_heredoc.c \
                          src/redirections/redirect_utils.c \
                          src/init.c \
                          src/builtins/ft_export.c \
                          src/builtins/ft_export_3.c \
                          src/builtins/ft_echo.c \
                          src/builtins/ft_exit.c \
                          src/builtins/ft_export_2.c \
                          src/builtins/ft_cd.c \
                          src/builtins/ft_unset.c \
                          src/builtins/exec_builtin.c \
                          src/builtins/ft_env.c \
                          src/builtins/ft_pwd.c \
                          src/init/init_env.c \
                          src/init/init_heredocs.c \
                          src/init/init_path.c \
                          src/init/init_pipes.c \
                          src/init/init_pids.c \
                          src/init/init_redirs.c \
                          src/signals/signals.c \
                          src/signals/cancel.c \
                          src/signals/backslash.c \
                          src/signals/display_prompt.c \
                          src/parsing/dup_parsing_queue.c \
                          src/parsing/space_trim.c \
                          src/parsing/parsing_queue_management.c \
                          src/parsing/parsing_filters/parse_expansions.c \
                          src/parsing/parsing_filters/remove_quotes.c \
                          src/parsing/parsing_filters/parse_spaces.c \
                          src/parsing/parsing_filters/parse_redirs/parse_dredir_in.c \
                          src/parsing/parsing_filters/parse_redirs/parse_dredir_out.c \
                          src/parsing/parsing_filters/parse_redirs/parse_redir_in.c \
                          src/parsing/parsing_filters/parse_redirs/parse_redir_out.c \
                          src/parsing/parsing_filters/parse_pipes.c \
                          src/parsing/parsing_filters/parse_quotes/parse_opening_doublequote.c \
                          src/parsing/parsing_filters/parse_quotes/parse_opening_singlequote.c \
                          src/parsing/parsing_filters/parse_quotes/parse_closing_doublequote.c \
                          src/parsing/parsing_filters/parse_quotes/parse_closing_singlequote.c \
                          src/parsing/parsing_steps/expand_variables.c \
                          src/parsing/parsing_steps/look_for_pipes_n_redirs.c \
                          src/parsing/parsing_steps/look_for_expansions.c \
                          src/parsing/parsing_steps/remodel_parsing.c \
                          src/parsing/parsing_steps/look_for_quotes.c \
                          src/parsing/parsing_steps/specify_tokens.c \
                          src/parsing/ignore_quotes.c \
                          src/parsing/parser.c \
                          src/parsing/set_index.c \
                          src/parsing/remove_empty_token.c \
                          src/parsing/check_type.c \
                          src/parsing/identify_args.c \
                          src/files/close_fd.c \
                          src/interactive.c \
                          src/minishell.c \
                          src/exec/exec.c \
                          src/exec/close_fds.c \
                          src/exec/t_type_handler.c \
                          src/exec/utils.c \
                          src/exec/exec_norm.c \
                          src/free/free_pids.c \
                          src/free/free_redirs.c \
                          src/free/free_heredocs.c \
                          src/free/free_tokens.c \
                          src/free/free_env.c \
                          src/free/free_env_exp.c \
                          src/free/free_path.c \
                          src/free/free_prog.c \
                          src/free/free_pipes.c \
                          src/utils.c \
                          src/tokens_lst.c \
                          lib/libft/src/ft_lstdelone.c \
                          lib/libft/src/ft_memcmp.c \
                          lib/libft/src/ft_lstadd_front.c \
                          lib/libft/src/get_next_line_utils.c \
                          lib/libft/src/ft_putchar.c \
                          lib/libft/src/ft_memcpy.c \
                          lib/libft/src/ft_calloc.c \
                          lib/libft/src/ft_putendl_fd.c \
                          lib/libft/src/ft_strnstr.c \
                          lib/libft/src/ft_print_hex.c \
                          lib/libft/src/ft_atoull.c \
                          lib/libft/src/ft_isalpha.c \
                          lib/libft/src/ft_strtrim.c \
                          lib/libft/src/ft_lstclear.c \
                          lib/libft/src/ft_memmove.c \
                          lib/libft/src/ft_print_char.c \
                          lib/libft/src/ft_isalnum.c \
                          lib/libft/src/ft_lstadd_back.c \
                          lib/libft/src/ft_isdigit.c \
                          lib/libft/src/ft_free_char_array.c \
                          lib/libft/src/ft_lstnew.c \
                          lib/libft/src/ft_lstsize.c \
                          lib/libft/src/ft_strjoin_new.c \
                          lib/libft/src/get_next_line.c \
                          lib/libft/src/ft_isprint.c \
                          lib/libft/src/ft_tolower.c \
                          lib/libft/src/ft_toupper.c \
                          lib/libft/src/ft_strncmp.c \
                          lib/libft/src/ft_printf.c \
                          lib/libft/src/ft_strlen.c \
                          lib/libft/src/ft_putstr_fd.c \
                          lib/libft/src/ft_bzero.c \
                          lib/libft/src/ft_memset.c \
                          lib/libft/src/ft_substr.c \
                          lib/libft/src/ft_strmapi.c \
                          lib/libft/src/ft_strchr.c \
                          lib/libft/src/ft_atoi.c \
                          lib/libft/src/ft_isascii.c \
                          lib/libft/src/ft_itoa.c \
                          lib/libft/src/ft_putchar_fd.c \
                          lib/libft/src/ft_atoll.c \
                          lib/libft/src/ft_strjoin.c \
                          lib/libft/src/ft_split.c \
                          lib/libft/src/ft_strlcat.c \
                          lib/libft/src/ft_print_ptr.c \
                          lib/libft/src/ft_lstiter.c \
                          lib/libft/src/ft_isdigit_str.c \
                          lib/libft/src/ft_isalphanum_str.c \
                          lib/libft/src/ft_print_int.c \
                          lib/libft/src/ft_lstmap.c \
                          lib/libft/src/ft_putnbr_fd.c \
                          lib/libft/src/ft_print_uint.c \
                          lib/libft/src/ft_memchr.c \
                          lib/libft/src/ft_strrchr.c \
                          lib/libft/src/ft_itob.c \
                          lib/libft/src/ft_striteri.c \
                          lib/libft/src/ft_strdup.c \
                          lib/libft/src/ft_lstlast.c \
                          lib/libft/src/ft_strlcpy.c \
                          lib/libft/src/ft_print_str.c \
                          
OBJS        := $(SRCS:.c=.o)

%.o: %.c includes/minishell.h
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -Iincludes -Ilib/libft/includes

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS} -Iincludes/minishell.h -lreadline -L.local/lib
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o */*/*/*.o */*/*/*/*/*.o */*/*/*/*/*/*.o */*/*/*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all
