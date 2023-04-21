# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 22:49:53 by jikoo             #+#    #+#              #
#    Updated: 2023/04/21 15:59:33 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			= rm -f
LIBFT		= -Llibft -lft
LDFLAGS		= -lreadline -L$(shell brew --prefix readline)/lib
CPPFLAGS	= -I$(shell brew --prefix readline)/include

# color
RESET	= \033[0m
GREEN	= \033[1;92m
CYAN	= \033[1;96m

# source files
MS_DIR		= srcs/

UTILS		= utils/environment_variables.c \
			  utils/token.c \
			  utils/signal.c \
			  utils/utils.c \
			  utils/utils2.c

LEXICAL		= lexical_analysis/lexical_analysis.c \
			  lexical_analysis/handle_heredoc_limiter.c	\
			  lexical_analysis/seperate_quotes.c \
			  lexical_analysis/handle_quotes.c \
			  lexical_analysis/seperate_environment_variables.c \
			  lexical_analysis/handle_environment_variables.c	\
			  lexical_analysis/seperate_token_by_arg.c \
			  lexical_analysis/handle_chunk.c \
			  lexical_analysis/merge_continuous_argv_token.c \
			  lexical_analysis/remove_space_token.c


SYNTAX		= syntax_analysis/syntax_analysis.c

EXCUTE		= execute/ms_execute.c \
			  execute/heredoc.c \
			  execute/set_redirection_fd.c \
			  execute/single_cmd.c \
			  execute/multiple_cmd.c \

CMD_LIST	= cmd_list/create_cmd_list.c \
			  cmd_list/free_cmd_list.c \
			  cmd_list/cmd_utils.c

BUILT_IN	= built_in/cd.c \
			  built_in/echo.c \
			  built_in/env.c \
			  built_in/exit.c \
			  built_in/export.c \
			  built_in/pwd.c \
			  built_in/unset.c

MS_SRCS		= main.c \
			  $(LEXICAL) \
			  $(SYNTAX) \
			  $(CMD_LIST) \
			  $(BUILT_IN) \
			  $(EXCUTE) \
			  $(UTILS)

MS_PATH		= $(addprefix $(MS_DIR), $(MS_SRCS))
MS_OBJS		= $(MS_PATH:c=o)

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(MS_OBJS)
	@make -sC libft all
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT) $^ -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║                   minishell                   ║$(RESET)"
	@echo "$(GREEN)║               compile finished.               ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	@make -C libft clean
	@$(RM) $(MS_OBJS)
	@echo "$(CYAN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║              make clean finished.             ║$(RESET)"
	@echo "$(CYAN)╚═══════════════════════════════════════════════╝$(RESET)"

fclean:
	@make -C libft fclean
	@make clean
	@$(RM) $(NAME)
	@echo "$(CYAN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║             make fclean finished.             ║$(RESET)"
	@echo "$(CYAN)╚═══════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re