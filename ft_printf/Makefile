# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 02:06:18 by okaname           #+#    #+#              #
#    Updated: 2024/11/13 02:42:51 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_next_arg.c \
       ft_printf.c \
       ft_type_arg.c \
       ft_write_arg.c \
       ft_write_func.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
