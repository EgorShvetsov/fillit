# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dorphan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 21:09:24 by dorphan           #+#    #+#              #
#    Updated: 2019/11/09 17:50:15 by dorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

SRC =  ft_atoi.c\
       ft_bzero.c\
       ft_isalnum.c\
       ft_isalpha.c\
       ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
   	   ft_memset.c\
	   ft_strcat.c\
	   ft_strchr.c\
	   ft_strcmp.c\
	   ft_strcpy.c\
	   ft_strdup.c\
	   ft_strlcat.c\
	   ft_strlen.c\
	   ft_strncat.c\
	   ft_strncmp.c\
	   ft_strncpy.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_isspace.c\
	   ft_islower.c\
	   ft_isupper.c\
	   ft_isblank.c\
	   ft_memalloc.c\
	   ft_memdel.c\
	   ft_putchar.c\
	   ft_putendl.c\
	   ft_putnbr.c\
	   ft_putstr.c\
	   ft_strclr.c\
	   ft_strdel.c\
	   ft_strequ.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strjoin.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strnequ.c\
	   ft_strnew.c\
	   ft_strsub.c\
	   ft_strtrim.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_itoa.c\
	   ft_strsplit.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_max.c\
	   ft_printbits.c\
	   gnl/get_next_line.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I. -c

all: $(NAME)

$(NAME): $(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

%.o: %.c libft.h
			$(CC) -o $@ $(FLAGS) $<
clean:
			/bin/rm -f $(OBJ)

fclean: clean
			/bin/rm -f $(NAME)

re: fclean all
