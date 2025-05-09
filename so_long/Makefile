# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 14:38:14 by dmusomec          #+#    #+#              #
#    Updated: 2025/04/11 20:00:25 by dmusomec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
MLX_DIR = ./minilibx-linux
MLX     = $(MLX_DIR)/libmlx.a
LIBFT   = ./libft/libft.a

# Sources and Objects
SRCS    = main.c flood_fill.c assemble_line.c gen_utils.c line_utils.c mlx_utils.c texture_utils.c
OBJS    = $(SRCS:.c=.o)
NAME    = so_long

# Linux-specific MLX flags
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re