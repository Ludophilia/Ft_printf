# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 15:37:04 by jegerman          #+#    #+#              #
#    Updated: 2024/11/28 15:58:09 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc
AR := ar

CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

SRCS_MAN := ft_printf.c

OBJS_MAN := $(SRCS_MAN:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_MAN)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJS_MAN)

fclean: clean
	rm -f $(NAME)

re: fclean all
