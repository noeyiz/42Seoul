# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 07:52:45 by jikoo             #+#    #+#              #
#    Updated: 2023/02/18 23:50:23 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
LIBFT		= -Llibft -lft

# source files
M_DIR		= mandatory/
M_SRCS		= main.c cmd.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

B_DIR		= bonus/
B_SRCS		= main_bonus.c cmd_bonus.c redir_bonus.c utils_bonus.c
B_PATH		= $(addprefix $(B_DIR), $(B_SRCS))
B_OBJS		= $(B_PATH:c=o)

G_DIR		= gnl/
G_SRCS		= get_next_line.c get_next_line_utils.c
G_PATH		= $(addprefix $(G_DIR), $(G_SRCS))
G_OBJS		= $(G_PATH:c=o)

# colors
RESET = \033[0m
GREEN = \033[1;32m
CYAN = \033[1;36m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(M_OBJS)
	@make -sC libft all
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $(NAME)
	@echo "$(GREEN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)║            pipex compile finished.          ║$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)╚═════════════════════════════════════════════╝$(RESET)"
	
bonus: $(B_OBJS) $(G_OBJS)
	@make -sC libft all
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $(NAME)
	@echo "$(GREEN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)║            pipex compile finished.          ║$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)╚═════════════════════════════════════════════╝$(RESET)"

clean:
	@make -C libft clean
	@$(RM) $(M_OBJS) $(B_OBJS) $(G_OBJS)
	@echo "$(CYAN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║             make clean finished.            ║$(RESET)"
	@echo "$(CYAN)╚═════════════════════════════════════════════╝$(RESET)"

fclean:
	@make -C libft fclean
	@make clean
	@$(RM) $(NAME)
	@echo "$(CYAN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║            make fclean finished.            ║$(RESET)"
	@echo "$(CYAN)╚═════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all bonus clean fclean re
