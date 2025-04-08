# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 21:20:06 by dmusomec          #+#    #+#              #
#    Updated: 2025/04/05 21:20:13 by dmusomec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ -Llibft -lft

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	make -C libft clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re