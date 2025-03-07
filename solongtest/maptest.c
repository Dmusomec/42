#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "printf/ft_printf.h"

typedef struct s_buffer {
    char    *data;
    size_t  size;
}   t_buffer;

//FUNCIONES AUXILIARES

static int  is_ber_file(const char *filename)
{
    char    *dot;

    dot = ft_strrchr(filename, '.');
    if (!dot || dot == filename)
        return (0);
    return (ft_strncmp(dot, ".ber", 5) == 0);
}

//Valida tamaño mínimo del mapa (3x3)
static int  validate_size(int rows, int cols)
{
    return (rows >= 3 && cols >= 3);
}

//MANEJO DE BUFFER

//Lee el archivo completo usando read()
static t_buffer read_file(int fd)
{
    t_buffer    buf;
    char        tmp[1024];
    ssize_t     bytes;

    buf.data = NULL;
    buf.size = 0;
    bytes = read(fd, tmp, 1024);
    while (bytes > 0)
    {
        if (!append_buffer(&buf, tmp, bytes))
            break;
        bytes = read(fd, tmp, 1024);
    }
    if (bytes < 0 || !buf.data)
    {
        free(buf.data);
        buf.data = NULL;
    }
    return (buf);
}

//Añade nuevos datos al buffer usando memcpy de libft
static int  append_buffer(t_buffer *buf, char *tmp, ssize_t bytes)
{
    char    *new_data;
    size_t  new_size;

    new_size = buf->size + bytes;
    new_data = malloc(new_size);
    if (!new_data)
        return (0);
    if (buf->data)
        ft_memcpy(new_data, buf->data, buf->size);
    ft_memcpy(new_data + buf->size, tmp, bytes);
    free(buf->data);
    buf->data = new_data;
    buf->size = new_size;
    return (1);
}

//PROCESADO DEL MAPA

//Analiza estructura del mapa y calcula dimensiones
static int  process_buffer(t_buffer b, int *rows, int *cols)
{
    size_t  i;
    size_t  start;
    size_t  line_len;
    size_t  prev_len;

    *rows = 0;
    prev_len = 0;
    start = 0;
    i = 0;
    while (i < b.size)
    {
        if (b.data[i] == '\n')
        {
            line_len = i - start;
            if (line_len == 0 || (*rows > 0 && line_len != prev_len))
                return (-1);
            prev_len = line_len;
            (*rows)++;
            start = i + 1;
        }
        i++;
    }
    //Verificar última línea
    if (start < b.size)
    {
        line_len = b.size - start;
        if (line_len != prev_len && *rows > 0)
            return (-1);
        (*rows)++;
        prev_len = line_len;
    }
    *cols = prev_len;
    return (0);
}

//FUNCIONES PRINCIPALES

//Función principal que coordina todo el proceso
int get_map_dimensions(const char *file, int *x, int *y)
{
    int         fd;
    t_buffer    buf;

    if (!is_ber_file(file))
        return (ft_printf("Error: Archivo debe ser .ber\n"), -1);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (perror("Error open"), -1);
    buf = read_file(fd);
    close(fd);
    if (!buf.data)
        return (ft_printf("Error: Archivo vacío o inválido\n"), -1);
    if (process_buffer(buf, x, y) == -1)
    {
        free(buf.data);
        return (ft_printf("Error: Mapa no rectangular\n"), -1);
    }
    if (!validate_size(*x, *y))
    {
        free(buf.data);
        return (ft_printf("Error: Mapa mínimo 3x3\n"), -1);
    }
    free(buf.data);
    return (0);
}

//Función de verificación de forma
int is_map_rectangular(const char *file)
{
    int x;
    int y;

    return (get_map_dimensions(file, &x, &y) == 0);
}