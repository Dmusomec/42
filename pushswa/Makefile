# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 19:52:07 by dmusomec          #+#    #+#              #
#    Updated: 2025/04/24 18:01:09 by dmusomec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./ -I./libft

# Sources
SRCS		= list_utils.c main.c radix.c stack_utils.c utils.c
OBJS		= $(SRCS:.c=.o)

# Libft
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re