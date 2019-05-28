# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madecreu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 19:31:29 by madecreu          #+#    #+#              #
#    Updated: 2018/04/12 19:31:37 by madecreu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FCC = -Wall -Werror -Wextra

MLX += -lmlx -framework OpenGL -framework AppKit

LIB += ./libft/libft.a

SRC = srcs/main.c \
	  srcs/reader.c \
	  srcs/fill_map.c \
	  srcs/window.c \
	  srcs/bresenham.c \
	  srcs/bresenham2.c \
	  srcs/event.c

OBJ = $(patsubst srcs/%.c, objs/%.o, $(SRC))

INCLUDES = includes/fdf.h 

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
