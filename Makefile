# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 15:37:04 by jegerman          #+#    #+#              #
#    Updated: 2024/12/04 18:22:44 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc
AR := ar

CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

LFT_DIR := libft

SRCS_MAN := ft_printf.c
SRCS_MAN += printer.c
SRCS_MAN += processor.c

OBJS_MAN := $(SRCS_MAN:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_MAN)
	make -sC $(LFT_DIR) && mv $(LFT_DIR)/libft.a ./$@
	$(AR) $(ARFLAGS) $@ $^

clean:
	make -C$(LFT_DIR) clean
	rm -f $(OBJS_MAN)

fclean: clean
	rm -f $(NAME)

re: fclean all
