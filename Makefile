# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 15:37:04 by jegerman          #+#    #+#              #
#    Updated: 2024/12/12 12:31:09 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc
AR := ar

CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

SRCSM_DIR := srcs
SRCSB_DIR := srcs_bonus

INCLM_DIR := includes
INCLB_DIR := includes_bonus

LIB_DIR  := libs

all: CFLAGS += -I$(INCLM_DIR)
bonus: CFLAGS += -I$(INCLB_DIR)

LFT_DIR := $(LIB_DIR)/libft

SRCS_MAN := $(SRCSM_DIR)/ft_printf.c
SRCS_MAN += $(SRCSM_DIR)/printer.c
SRCS_MAN += $(SRCSM_DIR)/processor.c

SRCS_BON := $(SRCSB_DIR)/ft_printf_bonus.c
SRCS_BON += $(SRCSB_DIR)/printer_bonus.c
SRCS_BON += $(SRCSB_DIR)/processor_bonus.c
SRCS_BON += $(SRCSB_DIR)/parser_bonus.c
SRCS_BON += $(SRCSB_DIR)/printer_helpers_bonus.c
SRCS_BON += $(SRCSB_DIR)/parser_helpers_bonus.c

OBJS_MAN := $(SRCS_MAN:.c=.o)
OBJS_BON := $(SRCS_BON:.c=.o)

all: $(NAME)

bonus: $(OBJS_BON) | all
	$(AR) ds $(NAME) $(OBJS_MAN)
	$(AR) $(ARFLAGS) $(NAME) $^

$(NAME): $(OBJS_MAN)
	make -sC $(LFT_DIR) && mv $(LFT_DIR)/libft.a ./$@
	$(AR) $(ARFLAGS) $@ $^

clean:
	make -C$(LFT_DIR) clean
	rm -f $(OBJS_MAN)
	rm -f $(OBJS_BON)

fclean: clean
	rm -f $(NAME)

re: fclean all
