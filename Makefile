# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2023/03/11 15:19:17 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CCFL = -Wall -Wextra -Werror

AR = ar
ARFL = -rcs

PRS = parser
PRT = printer

SRCS = ft_printf.c $(PRS)/parser.c $(PRT)/printer.c
OBJS = $(SRCS:.c=.o)

LFTDR = libft
LFT = $(LFTDR)/libft.a

all: $(LFT) $(NAME)

$(LFT):
	make -C libft all

$(NAME): $(OBJS) 
	$(AR) $(ARFL) $@ $^

# I want each .o to appaear in their original file
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

.PHONY: all clean fclean re