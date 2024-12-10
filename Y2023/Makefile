# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:16:47 by jgermany          #+#    #+#              #
#    Updated: 2024/01/05 16:22:51 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME							:= libftprintf.a

CC								:= cc
AR								:= ar

CFLAGS							:= -Wall -Wextra -Werror
ARFLAGS							:= -rcs

SRCS_DR							:= srcs
SRCS_BDR						:= srcs_bonus
LFT_DR							:= libs/libft
INCL_DR							:= includes

LFT								:= $(LFT_DR)/libft.a

MAN_HDR							:= $(INCL_DR)/ft_printf.h
MAN_SRCS						:= $(SRCS_DR)/ft_printf.c
MAN_SRCS						+= $(SRCS_DR)/parser.c
MAN_SRCS						+= $(SRCS_DR)/printer.c

BON_HDR							:= $(INCL_DR)/ft_printf_bonus.h
BON_SRCS						:= $(SRCS_BDR)/ft_printf_bonus.c
BON_SRCS						+= $(SRCS_BDR)/parser_bonus.c
BON_SRCS						+= $(SRCS_BDR)/parser_helpers_bonus.c
BON_SRCS						+= $(SRCS_BDR)/printer_bonus.c
BON_SRCS						+= $(SRCS_BDR)/printer_checkers_bonus.c
BON_SRCS						+= $(SRCS_BDR)/printer_helpers_bonus.c
BON_SRCS						+= $(SRCS_BDR)/writer_bonus.c
BON_SRCS						+= $(SRCS_BDR)/writer_helpers_bonus.c

MAN_OBJS						:= $(MAN_SRCS:.c=.o)
BON_OBJS						:= $(BON_SRCS:.c=.o)

all:							$(NAME)

bonus:							$(BON_OBJS)
								make -C $(LFT_DR) all bonus
								cp $(LFT) $(NAME)
								$(AR) $(ARFLAGS) $(NAME) $^

$(NAME):						$(MAN_OBJS)
								make -C $(LFT_DR) all
								cp $(LFT) $@
								$(AR) $(ARFLAGS) $@ $^

%.o:							%.c $(MAN_HDR)
								$(CC) $(CFLAGS) $< -c -o $@ -I$(INCL_DR)
								
%_bonus.o:						%.c $(BON_HDR)
								$(CC) $(CFLAGS) $< -c -I$(INCL_DR)

clean:
								rm -f $(MAN_OBJS) $(BON_OBJS)
								make -C $(LFT_DR) clean

fclean:							clean
								rm -f $(NAME)
								make -C $(LFT_DR) fclean

re:
								make fclean
								make all

.PHONY:							all bonus clean fclean re
.SILENT:						clean fclean
.DELETE_ON_ERROR:
