# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/03/03 16:49:59 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CCFL = -Wall -Wextra -Werror

AR = ar
ARFL = -rcs

SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

LFTDR = libft
LFT = $(LFTDR)/libft.a

all: $(LFT) $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(ARFL) $@ $^

$(LFT):
	make -C libft

%.o: %.c
	$(CC) $(CCFL) -c $<

clean:
	rm -rf $(OBJ)
	make -C $(LFTDR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LFTDR) fclean

re:
	make fclean
	make all
