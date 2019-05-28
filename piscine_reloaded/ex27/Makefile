# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madecreu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:36:54 by madecreu          #+#    #+#              #
#    Updated: 2017/11/07 21:49:57 by madecreu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_display_file

SRC= main.c

OBJ= main.o

CC= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	gcc $(CC) $(SRC) -o $(NAME)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean 
	/bin/rm -f $(NAME)

re: fclean all
