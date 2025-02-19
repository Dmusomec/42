CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./minilibx-linux
MINILIBXPATH = ./minilibx-linux
MLXFLAGS = -lm -lXext -lX11

SRCS = pruebas.c minilibx-linux/mlx.h minilibx-linux/libmlx.a
OBJS = $(SRCS:.c=.o)
TARGET = solejos
TEXTURES = textures/luffy.xpm

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C $(MINILIBXPATH)
	
	$(CC) $(OBJS) $(MLXFLAGS) -o $(TARGET)
	@echo "Fatto ciccio."

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(TARGET)

fanculo:
	clean
	fclean

re: fclean all

.PHONY: all clean fclean re
.SILENT: