# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:04:51 by jikoo             #+#    #+#              #
#    Updated: 2023/04/13 00:58:15 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread #-fsanitize=address -g3
RM			= rm -f

# source files
SRCS		= main.c init_free.c simulate.c routine.c utils.c
OBJS		= $(SRCS:c=o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "╔═════════════════════════════════════════════╗"
	@echo "║                                             ║"
	@echo "║                🍽   philo   🍽                ║"
	@echo "║               compile finished              ║"
	@echo "║                                             ║"
	@echo "╚═════════════════════════════════════════════╝"

clean:
	@$(RM) $(OBJS)
	@echo "╔═════════════════════════════════════════════╗"
	@echo "║             make clean finished.            ║"
	@echo "╚═════════════════════════════════════════════╝"

fclean:
	@make clean
	@$(RM) $(NAME)
	@echo "╔═════════════════════════════════════════════╗"
	@echo "║            make fclean finished.            ║"
	@echo "╚═════════════════════════════════════════════╝"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
