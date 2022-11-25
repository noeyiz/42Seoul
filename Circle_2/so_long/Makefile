# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 13:59:18 by jikoo             #+#    #+#              #
#    Updated: 2022/11/25 14:09:07 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX			= -lmlx -framework OpenGL -framework Appkit

# header files
HEADER_DIR  = includes/
HEADER_SRCS	= so_long.h so_long_bonus.h
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# source files
M_DIR		= mandatory/
M_SRCS      = main.c map.c map_checker.c sprites.c move.c game.c utils.c utils2.c get_next_line.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

B_DIR		= bonus/
B_SRCS		= main_bonus.c map_bonus.c map_checker_bonus.c score_bonus.c player_bonus.c \
			  enemy_bonus.c sprites_bonus.c move_bonus.c move_enemy_bonus.c game_bonus.c \
			  utils_bonus.c utils2_bonus.c get_next_line_bonus.c
B_PATH		= $(addprefix $(B_DIR), $(B_SRCS))
B_OBJS		= $(B_PATH:c=o)

# colors
RESET = \033[0m
GREEN = \033[1;32m
CYAN = \033[1;36m

ifdef BONUSFLAG
	OBJS = $(B_OBJS)
else
	OBJS = $(M_OBJS)
endif

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $(OBJS)
	@echo "$(GREEN)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║       so_long compile finished :)      ║$(RESET)"
	@echo "$(GREEN)╠════════════════════════════════════════╣$(RESET)"
	@echo "$(GREEN)║                                        ║$(RESET)"
	@echo "$(GREEN)║                     Have fun !         ║$(RESET)"
	@echo "$(GREEN)║                                        ║$(RESET)"
	@echo "$(GREEN)╚════════════════════════════════════════╝$(RESET)"

all: $(NAME)

bonus:
	make BONUSFLAG=1

clean:
	rm -rf $(M_OBJS)
	rm -rf $(B_OBJS)
	@echo "$(CYAN)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║           make clean finished.         ║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════════╝$(RESET)"

fclean: 
	make clean
	rm -rf $(NAME)
	@echo "$(CYAN)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║          make fclean finished.         ║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════════╝$(RESET)"

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
