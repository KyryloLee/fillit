# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 11:04:05 by klee              #+#    #+#              #
#    Updated: 2017/11/16 09:39:36 by klee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ft_isvalid.c ft_recognize.c right_fillit.c read_input.c main.c\
ft_memset.c \
ft_bzero.c \
ft_strlen.c \
ft_strdup.c \
ft_strlcat.c \
ft_strnew.c \
ft_strdel.c \
ft_strsub.c \
ft_putchar.c \
ft_putstr.c \
ft_putendl.c \

OBJECT = $(SRCS:.c=.o)

INCLUDES = libft.h lst_elements.h


all: $(NAME)

$(NAME):
	gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(SRCS)
	gcc -Wall -Wextra -Werror $(OBJECT) $(LBR) -o $(NAME)
	rm -f lst_elements.h.gch
	rm -f .DS_Store

clean:
	rm -f *.o 
	rm -f *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

