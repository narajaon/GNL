# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: narajaon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 18:59:25 by narajaon          #+#    #+#              #
#    Updated: 2017/04/24 12:31:53 by narajaon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean
.SUFFIXES:

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
COPTION = -c -I
srcdir =
includedir = ./includes/
libdir =


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(COPTION) $(includedir) $(srcdir)*.c
	ar rc $(libdir)$(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(libdir)$(NAME)

re: fclean all
