# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/02/14 18:36:16 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
# CCFL = -Wall -Wextra -Werror

# SOURCES = $()
# OBJECTS = $(SOURCES: .c=.o)

test:
	@$(CC) $(CCFL) main.c && ./a.out





all: $(NAME)

$(NAME): #sources .o
	ar -rcs $@ $^

%.o: %.c
#	recipe

#More shit here

clean:
#	rm -rf objects

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re:
	make fclean
	make all
