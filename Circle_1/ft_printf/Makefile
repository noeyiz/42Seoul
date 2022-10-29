# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 20:59:46 by jikoo             #+#    #+#              #
#    Updated: 2022/10/29 13:22:07 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc

CFLAGS      = -Wall -Wextra -Werror

HEADER      = ft_printf.h

SRCS        = ft_printf.c ft_printf_utils.c ft_print_chr.c ft_print_str.c \
			  ft_print_nbr.c ft_print_ptr.c

OBJS		= $(SRCS:c=o)

NAME		= libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re