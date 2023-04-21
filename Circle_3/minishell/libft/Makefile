# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 01:53:44 by jikoo             #+#    #+#              #
#    Updated: 2023/04/19 20:51:58 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# source files
SRCS		= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			  ft_isspace.c ft_memcpy.c ft_memset.c ft_putchar_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			  ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strjoin.c \
			  ft_strlen.c ft_strncmp.c ft_strndup.c ft_strrepl.c ft_substr.c \
			  ft_abs.c ft_max.c ft_min.c ft_itoa.c
OBJS		= $(SRCS:c=o)

# color
RESET	= \033[0m
GREEN	= \033[1;92m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║             Libft compile finished            ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean:
	@make clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
