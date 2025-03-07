CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./minilibx-linux
MINILIBXPATH = ./minilibx-linux
MLXFLAGS = -lm -lXext -lX11

SRCS = pruebas.c
OBJS = $(SRCS:.c=.o)
TARGET = solejos

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -s -C $(MINILIBXPATH)
	$(CC) $^ -L$(MINILIBXPATH) -lmlx $(MLXFLAGS) -o $@
	@echo "Fatto ciccio."

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
.SILENT: