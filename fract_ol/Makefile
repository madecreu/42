# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madecreu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 19:31:29 by madecreu          #+#    #+#              #
#    Updated: 2018/09/20 03:57:01 by madecreu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FCC = -Wall -Werror -Wextra

MLX += -lmlx -framework OpenGL -framework AppKit -O3

LIB += ./libft/libft.a

SRC = srcs/burning.c \
	  srcs/color.c \
	  srcs/event.c \
	  srcs/event_burning.c \
	  srcs/event_julia.c \
	  srcs/event_mandelbrot.c \
	  srcs/event_mouse.c \
	  srcs/event_tricorn.c \
	  srcs/julia.c \
	  srcs/main.c \
	  srcs/mandelbrot.c \
	  srcs/tricorn.c

OBJ = $(patsubst srcs/%.c, objs/%.o, $(SRC))

INCLUDES = incs/fract_ol.h 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31m"
	make -C libft/
	@echo ".o created"
	$(CC) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	@echo "Compilation done\033[0m"

objs/%.o: srcs/%.c
	@echo "\033[32m"
	mkdir -p objs
	$(CC) -o $@ -c $< $(FCC)
	@echo "\033[0m"

clean: 
	@echo "\033[33m"
	rm -f $(OBJ)
	make -C libft/ clean
	@echo "All .o are removed"
	@echo "\033[0m"

fclean: clean
	@echo "\033[34m"
	rm -f $(NAME)
	make -C libft/ fclean 
	rm -rf objs
	@echo "Everything is clean !"
	@echo "\033[0m"

re: fclean all
