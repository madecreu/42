# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madecreu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:36:54 by madecreu          #+#    #+#              #
#    Updated: 2017/11/07 17:44:40 by madecreu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRC= srcs/ft_putchar.c \
	 srcs/ft_putstr.c \
	 srcs/ft_strcmp.c \
	 srcs/ft_strlen.c \
	 srcs/ft_swap.c

OBJ= ft_putchar.o \
	 ft_putstr.o \
	 ft_strlen.o \
	 ft_strcmp.o \
	 ft_swap.o

CC= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	gcc -c $(CC) $(SRC) && ar rc $(NAME) $(OBJ) && ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean 
	/bin/rm -f $(NAME)

re: fclean all
