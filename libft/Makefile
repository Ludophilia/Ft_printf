# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 12:44:08 by jegerman          #+#    #+#              #
#    Updated: 2024/11/20 16:27:07 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcs

SRCS := ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c

SRCS += ft_strlen.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c

SRCS += ft_strlcpy.c
SRCS += ft_strlcat.c

SRCS += ft_toupper.c
SRCS += ft_tolower.c
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strncmp.c

SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strnstr.c

SRCS += ft_atoi.c
SRCS += ft_calloc.c
SRCS += ft_strdup.c

SRCS += ft_substr.c
SRCS += ft_strjoin.c
SRCS += ft_strtrim.c
SRCS += ft_split.c

SRCS += ft_itoa.c

SRCS += ft_strmapi.c
SRCS += ft_striteri.c

SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c

OBJS := $(SRCS:.c=.o)

SRCS_B := ft_lstnew_bonus.c
SRCS_B += ft_lstadd_front_bonus.c
SRCS_B += ft_lstsize_bonus.c
SRCS_B += ft_lstlast_bonus.c
SRCS_B += ft_lstadd_back_bonus.c
SRCS_B += ft_lstdelone_bonus.c
SRCS_B += ft_lstclear_bonus.c
SRCS_B += ft_lstiter_bonus.c
SRCS_B += ft_lstmap_bonus.c

OBJS_B := $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus: $(OBJS_B)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all
