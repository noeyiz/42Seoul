# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 01:36:59 by jikoo             #+#    #+#              #
#    Updated: 2023/01/29 18:07:14 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= push_swap
BONUS_NAME	= checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -f
LIBFT		= -Llibft -lft

# source files
M_DIR		= mandatory/
M_SRCS      = main.c swap.c push.c rotate.c reverse_rotate.c \
			  stack_operator.c create_stack.c parse_args.c check_args.c \
			  init_stack.c sort_stack.c move_from_b_to_a.c find_location.c utils.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

B_DIR		= bonus/
B_SRCS      = main_bonus.c swap_bonus.c push_bonus.c rotate_bonus.c reverse_rotate_bonus.c \
			  stack_operator_bonus.c create_stack_bonus.c parse_args_bonus.c check_args_bonus.c \
			  init_stack_bonus.c checker_bonus.c utils_bonus.c
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

bonus: $(BONUS_NAME)

$(NAME): $(M_OBJS)
	@make -sC libft all
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@
	@echo "$(GREEN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)║          push_swap compile finished.        ║$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)╚═════════════════════════════════════════════╝$(RESET)"

$(BONUS_NAME): $(B_OBJS) $(G_OBJS)
	@make -sC libft all
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@
	@echo "$(GREEN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                             ║$(RESET)"
	@echo "$(GREEN)║           checker compile finished.         ║$(RESET)"
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
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(CYAN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║            make fclean finished.            ║$(RESET)"
	@echo "$(CYAN)╚═════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all
	@make bonus

.PHONY: all bonus clean fclean re
