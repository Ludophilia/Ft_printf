# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/02/28 22:30:13 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# LFTDR = libft
# LFT = libft.a

CC = cc
CCFL = -Wall -Wextra -Werror

AR = ar
ARFL = -rcs

SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFL) $@ $^

%.o: %.c
	$(CC) $(CCFL) -c $<

# $(LFT): libft/libft.a
# 	make -C libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all
