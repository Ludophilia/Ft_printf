# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/03/06 21:18:27 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CCFL = -Wall -Wextra -Werror

AR = ar
ARFL = -rcs

SRCS = ft_printf.c parser.c
OBJS = $(SRCS:.c=.o)

LFTDR = libft
LFT = $(LFTDR)/libft.a

all: $(LFT) $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(ARFL) $@ $^

$(LFT):
	make -C libft all

%.o: %.c
	$(CC) $(CCFL) -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LFTDR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LFTDR) fclean

re:
	make fclean
	make all
