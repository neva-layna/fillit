# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlayna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 16:45:18 by nlayna            #+#    #+#              #
#    Updated: 2019/07/13 15:50:18 by nlayna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit

INCDIR	:= ./includes
LIBDIR	:= ./libft

SRC		:= main.c solver.c reader.c
OBJ		:= main.o solver.o reader.o
LIB		:= $(LIBDIR)/libft.a

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ -I $(INCDIR) $(OBJ) $(LIB)

$(LIB):
	make -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -rf *.o
	make clean -C $(LIBDIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all
