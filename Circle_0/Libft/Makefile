# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 14:33:45 by jikoo             #+#    #+#              #
#    Updated: 2022/11/26 20:38:31 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -f

HEADER      = libft.h
SRCS        = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS       = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS        = $(SRCS:c=o)
OBJS_BONUS  = $(BONUS:c=o)

ifdef BONUSFLAG
    ALLOBJ  = $(OBJS) $(OBJS_BONUS)
else
    ALLOBJ  = $(OBJS)
endif

NAME        = libft.a

all: $(NAME)
	sleep 1

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(ALLOBJ)
	ar rcs $@ $(ALLOBJ)

bonus:
	make BONUSFLAG=1

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
