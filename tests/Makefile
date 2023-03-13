# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 22:31:17 by jgermany          #+#    #+#              #
#    Updated: 2023/03/13 16:07:44 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.out

CC = cc
CCFL = -Wall -Wextra -Werror

MAIN = main.c
MAIN_OB = $(MAIN:.c=.o)

ROOT = ..
PADR = $(ROOT)/parser
PRDR = $(ROOT)/printer

LPF = $(ROOT)/libftprintf.a
LFTDR = $(ROOT)/libft

PFDR = $(ROOT)
PF = $(PADR)/parser.c $(ROOT)/ft_printf.c $(PRDR)/printer.c

all: $(NAME)
	./$<

mtest: $(NAME)
	valgrind ./$<

$(NAME): $(MAIN) $(LPF)
	$(CC) $(CCFL) -o $@ $(MAIN) -lftprintf -L$(ROOT) -lft -L$(LFTDR)

$(LPF): $(PF)
	make -C $(ROOT) all

clean:
	make -C $(ROOT) clean
	
fclean: clean
	rm -rf $(NAME)
	make -C $(ROOT) fclean

re:
	make fclean
	make all

.PHONY: all clean fclean re