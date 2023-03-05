# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:44:14 by jgermany          #+#    #+#              #
#    Updated: 2023/03/04 14:54:57 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = variadics.out

CC = cc
CCFL = -Wall -Wextra -Werror

SRCS = variadics.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	./$<

$(NAME): $(SRCS)
	$(CC) $(CCFL) -o $@ $^

%.o: %.c
	$(CC) $(CCFL) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all