#group cc con las flags determinadas
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
#nombre libreria
NAME = libft.a
all: $(NAME)
#los files que debe compilar
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c
#me crea los files .c como objetos
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS_BONUS:.c=.o)
#comando final para crear efectivamente cada file con "nombre".o
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(OBJS) $(OBJS2)
fclean: clean
	rm -f $(NAME)
re: fclean all