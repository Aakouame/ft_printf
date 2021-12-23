# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 15:29:37 by akouame           #+#    #+#              #
#    Updated: 2021/12/14 18:08:38 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_putnbr_base.c \
		ft_check.c \
		ft_u.c \
		ft_p.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
%.o:%.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@ -I ft_printf.h

re : fclean all
.PHONY: all fclean clean re 
