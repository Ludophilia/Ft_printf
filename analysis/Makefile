# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/02/28 23:03:55 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf_examples.out
SRC = $(NAME:.out=.c)
CC = cc
CCFL =

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CCFL) -o $@ $<
	@./$@

clean:
	rm -rf $(NAME)

fclean: clean

re:
	make fclean
	make all