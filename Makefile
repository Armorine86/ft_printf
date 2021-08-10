# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 13:40:31 by armorine          #+#    #+#              #
#    Updated: 2021/06/11 13:22:42 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			
CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c

SRCS=./libft/ft*.c ./srcs/ft*.c

OBJECTS =ft*.o
LIB_PATH = ./libft
INCLUDES=./includes

all:$(NAME)

$(NAME):
	@make re -C $(LIB_PATH)
	@$(CC) -g3 $(CFLAGS) $(SRCS) -I$(INCLUDES)
	@ar rc $(NAME) $(OBJECTS) $(LIB_PATH)/*.o
	@ranlib $(NAME)

bonus: re

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)


fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
