# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 14:38:14 by dmusomec          #+#    #+#              #
#    Updated: 2025/03/10 17:01:10 by dmusomec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= solong.a
CC			= cc
INC			= -I. -I./libft -I./minilibx-linux -lmlx -lX11 -lXext -lm
CFLAGS		= -Wall -Wextra -g
LIBSPATH	= ./libft
LIBCMP		= ar rcs
RM			= rm -f
SRC 		= map_parse.c \

SRC_OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	$(MAKE) -C $(LIBSPATH)
	$(CC) $(CFLAGS) $(SRC_OBJ) -L$(LIBSPATH) -lft $(MLIBXFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBSPATH)
	$(RM) $(SRC_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBSPATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: