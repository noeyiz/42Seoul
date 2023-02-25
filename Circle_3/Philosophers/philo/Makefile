# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 16:20:18 by jikoo             #+#    #+#              #
#    Updated: 2023/02/25 14:36:17 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# colors
RESET 	= \033[0m
GREEN 	= \033[1;32m
MAGENTA = \033[1;35m
CYAN 	= \033[1;36m

# source files
SRCS		= main.c
OBJS		= $(SRCS:c=o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(CYAN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║                                             ║$(RESET)"
	@echo "$(CYAN)║                🍽   philo   🍽                ║$(RESET)"
	@echo "$(CYAN)║               compile finished              ║$(RESET)"
	@echo "$(CYAN)║                                             ║$(RESET)"
	@echo "$(CYAN)╚═════════════════════════════════════════════╝$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║             make clean finished.            ║$(RESET)"
	@echo "$(MAGENTA)╚═════════════════════════════════════════════╝$(RESET)"

fclean:
	@make clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║            make fclean finished.            ║$(RESET)"
	@echo "$(MAGENTA)╚═════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
