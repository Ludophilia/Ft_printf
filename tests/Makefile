# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 22:31:17 by jgermany          #+#    #+#              #
#    Updated: 2023/03/06 21:18:55 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.out

CC = cc
CCFL = -Wall -Wextra -Werror

MAIN = main.c
MAIN_OB = $(MAIN:.c=.o)

ROOT = ..
LPF = $(ROOT)/libftprintf.a
LFTDR = $(ROOT)/libft

all: $(NAME)
	./$<

$(NAME): $(LPF) $(MAIN)
	$(CC) $(CCFL) $(MAIN) -lft -lftprintf -L$(ROOT) -L$(LFTDR) -o $@

$(LPF):
	make -C $(ROOT) all

clean:
	make -C $(ROOT) clean
	
fclean: clean
	rm -rf $(NAME)
	make -C $(ROOT) fclean

re:
	make fclean
	make all
