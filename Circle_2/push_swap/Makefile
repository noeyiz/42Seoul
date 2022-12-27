# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 01:36:59 by jikoo             #+#    #+#              #
#    Updated: 2022/12/27 22:16:56 by jikoo            ###   ########.fr        #
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
M_SRCS      = main.c args.c init_stack.c index_stack.c sort_stack.c utils.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

C_DIR		= command/
C_SRCS      = swap.c push.c rotate.c reverse_rotate.c
C_PATH		= $(addprefix $(C_DIR), $(C_SRCS))
C_OBJS		= $(C_PATH:c=o)

S_DIR		= stack/
S_SRCS      = operator.c create.c
S_PATH		= $(addprefix $(S_DIR), $(S_SRCS))
S_OBJS		= $(S_PATH:c=o)

# colors
RESET = \033[0m
GREEN = \033[1;32m
CYAN = \033[1;36m

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(M_OBJS) $(C_OBJS) $(S_OBJS)
	@make -C libft all
	@$(CC) $(CFLAGS) $(LIBFT) $(M_OBJS) $(C_OBJS) $(S_OBJS) -o $@
	@echo "$(GREEN)╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                            ║$(RESET)"
	@echo "$(GREEN)║          push_swap compile finished        ║$(RESET)"
	@echo "$(GREEN)║                                            ║$(RESET)"
	@echo "$(GREEN)╚════════════════════════════════════════════╝$(RESET)"

clean:
	@make -C libft clean
	@$(RM) $(M_OBJS)
	@$(RM) $(C_OBJS)
	@$(RM) $(S_OBJS)
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
