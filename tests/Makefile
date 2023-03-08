# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 22:31:17 by jgermany          #+#    #+#              #
#    Updated: 2023/03/08 14:26:29 by jgermany         ###   ########.fr        #
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

PFDR = $(ROOT)
PF = $(ROOT)/parser.c $(ROOT)/ft_printf.c $(ROOT)/displayer.c

all: $(NAME)
	./$<

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