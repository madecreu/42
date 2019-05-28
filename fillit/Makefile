# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:38:07 by acastryc          #+#    #+#              #
#    Updated: 2017/11/30 20:07:15 by madecreu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FCC = -Wall -Werror -Wextra

DEBUGFLAGS = -fsanitize=address -g3

SRC = main.c \
	  ft_display_error.c \
	  ft_check_tetris.c \
	  map_modifier.c \
	  push_pieces.c	\
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_malloc_map.c \
	  ft_putchar_fd.c \
	  ft_tablen.c \
	  ft_print_map.c \
	  ft_fill_map.c \
	  backtracking.c \
	  ft_bzero.c \
	  ft_memset.c \
	  onreessaye.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putchar.c 

OBJ = $(SRC:.c=.o)

INCLUDES = fillit.h 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FCC) -c $(SRC)
	@echo ".o created"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Compilation done"

%.o: %.c
	@$(CC) -o $@ -c $< $(FCC)

debug: $(OBJ)
	@$(CC) $(DEBUGFLAGS) $(FCC) -c $(SRC)
	@echo ".o created"
	@$(CC) $(DEBUGFLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation done, debug ready"

clean: 
	@rm -f $(OBJ)
	@echo "All .o are removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Everything is clean !"

re: fclean all
