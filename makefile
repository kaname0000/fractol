# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 21:37:38 by okaname           #+#    #+#              #
#    Updated: 2025/02/19 21:40:54 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes 

MANDATORY = fractol

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

MLXDIR = ./mlx
MLX = $(MLXDIR)/libmlx.a
LMLX = -L$(MLXDIR) -lmlx -lXext -lX11

SRCS = gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		main.c \
		mandelbrot.c\
		julia.c\
		ship.c\
		calculate.c \
		clear.c \
		hooks.c \
		pixel_put.c \
		set_data.c \
		move_pixel.c \

OBJS = $(SRCS:.c=.o)

all: $(MANDATORY)

$(MANDATORY): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LMLX) -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

$(PRINTF):
	make -C $(PRINTFDIR)

$(MLX):
	make -C $(MLXDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	make -C $(LIBFTDIR) clean
	make -C $(PRINTFDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(MANDATORY) 
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTFDIR) fclean
	make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re
