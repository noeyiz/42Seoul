# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:50:55 by jikoo             #+#    #+#              #
#    Updated: 2022/11/25 18:28:49 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX			= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT		= -Llibft -lft

# header files
HEADER_DIR  = includes/
HEADER_SRCS	= so_long.h
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# source files
M_DIR		= mandatory/
M_SRCS      = main.c map.c map_checker.c map_path_checker.c sprites.c \
			  move.c game.c utils.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

B_DIR		= bonus/
B_SRCS      = main_bonus.c map_bonus.c map_checker_bonus.c map_path_checker_bonus.c \
			  sprites_bonus.c move_bonus.c game_bonus.c utils_bonus.c
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

ifdef BONUSFLAG
	OBJS = $(B_OBJS)
else
	OBJS = $(M_OBJS)
endif

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(G_OBJS) $(M_OBJS)
	@make -C mlx all
	@make -C libft all
	@$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(G_OBJS) $(M_OBJS) -o $@
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
	@make -C mlx clean
	@make -C libft clean
	@rm -rf $(G_OBJS)
	@rm -rf $(M_OBJS)
	@rm -rf $(B_OBJS)
	@echo "$(CYAN)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║           make clean finished.         ║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════════╝$(RESET)"

fclean:
	@make -C libft fclean
	@make clean
	@rm -rf $(NAME)
	@echo "$(CYAN)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║          make fclean finished.         ║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════════╝$(RESET)"

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
