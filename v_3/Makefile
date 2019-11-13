# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dorphan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 17:52:39 by dorphan           #+#    #+#              #
#    Updated: 2019/11/09 17:56:08 by dorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

SRC =  check_solution.c\
       work_with_list.c\
       validator.c\
       types.c\
	   sqr_checker.c\
	   solver.c\
	   solution.c\
	   map.c\
	   lst_copy.c\
	   magic.c\
	   main.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIBFT = libft/

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o: 		%.c -I
			$(CC) -o $@ $(FLAGS) $<

clean:		
			rm -f $(OBJ)
			make -C $(LIBFT) clean

fclean: 	clean
			rm -f $(NAME)
			make -C $(LIBFT) fclean

re: 		fclean all
