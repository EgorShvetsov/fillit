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
	   create_matrix.c\
	   magic.c\
	   main.c

OBJ = $(SRC:.c=.o)

FLAGS = gcc -Wall -Wextra -Werror

all: $(NAME) $(OBJ)

$(NAME):
		$(FLAGS) libft/libft.a $(NAME) -o $@  $<

$(OBJ): %.o: %.c

clean:
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all
