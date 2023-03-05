# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/03/04 14:38:19 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf_examples.out

SRC = printf_examples.c
OBJ = $(SRC:.c=.o)

CC = cc
CCFL =

all: $(NAME)
	./$<

$(NAME): $(OBJ)
	$(CC) $(CCFL) -o $@ $^

%.o: %.c
	$(CC) $(CCFL) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all