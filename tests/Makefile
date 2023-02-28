# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 22:31:17 by jgermany          #+#    #+#              #
#    Updated: 2023/02/28 23:04:34 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.out

CC = cc
CCFL = -Wall -Wextra -Werror

MAIN = main.c

ROOT = ..
LFTDR = $(ROOT)/libft
LFT = $(LFTDR)/libft.a
LPF = $(ROOT)/libftprintf.a

all: $(NAME)
	./$<

$(NAME): $(LFT) $(LPF)
	$(CC) $(CCFL) $(MAIN) -lft -lftprintf -L$(ROOT) -L$(LFTDR) -o $@

$(LFT):
	make -C $(LFTDR)

$(LPF):
	make -C $(ROOT)

clean:
	make -C $(LFTDR) clean
	make -C $(ROOT) clean
	
fclean: clean
	rm -rf $(NAME)
	make -C $(LFTDR) fclean
	make -C $(ROOT) fclean

re:
	make fclean
	make all
