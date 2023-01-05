# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 01:36:59 by jikoo             #+#    #+#              #
#    Updated: 2023/01/05 18:03:30 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -f
LIBFT		= -Llibft -lft

# header files
HEADER_DIR  = includes/
HEADER_SRCS	= push_swap.h
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# source files
M_DIR		= mandatory/
M_SRCS      = main.c swap.c push.c rotate.c reverse_rotate.c \
			  stack_operator.c create_stack.c args.c \
			  init_stack.c index_stack.c sort_stack.c utils.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

# colors
RESET = \033[0m
GREEN = \033[1;32m
CYAN = \033[1;36m

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(M_OBJS)
	@make -C libft all
	@$(CC) $(CFLAGS) $(LIBFT) $(M_OBJS) -o $@
	@echo "$(GREEN)╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                            ║$(RESET)"
	@echo "$(GREEN)║          push_swap compile finished        ║$(RESET)"
	@echo "$(GREEN)║                                            ║$(RESET)"
	@echo "$(GREEN)╚════════════════════════════════════════════╝$(RESET)"

clean:
	@make -C libft clean
	@$(RM) $(M_OBJS)
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
	make fclean
	make all

.PHONY: all bonus clean fclean re
