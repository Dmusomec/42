# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 19:33:04 by dmusomec          #+#    #+#              #
#    Updated: 2025/03/10 15:56:02 by dmusomec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC			= cc
INC			= -I. -I./libft
LIBFTPATH 	= ./libft
CFLAGS		= -Wall -Wextra -Werror -g
LIBCMP		= ar rcs
RM			= rm -f
SRC 		= ft_printf.c \
			printf_utils.c \

SRC_OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	$(MAKE) -C $(LIBFTPATH)
	mv $(LIBFTPATH)/libft.a $(NAME)
	$(LIBCMP) $(NAME) $(SRC_OBJ)

clean:
	$(MAKE) clean -C $(LIBFTPATH)
	$(RM) $(SRC_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: