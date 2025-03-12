//cc -lm -lXext -lX11 solejos.c minilibx-linux/libmlx.a

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_data {
    void    *mlx;
    void    *wind;
    void    *img;
    char    *addr;
    int     width;
    int     height;
}           t_data;

int handle_input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->wind);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(1);
    }
    return (0);
}

int    dinomove(t_data *data)
{
    static int i = 0;
    static int c = 0;
    if (c <= 30)
    {
        if (i == 30 && c != 30)
        {
            i = 0;
            c++;
        }
        mlx_put_image_to_window(data->mlx, data->wind, data->img, i*data->width, c*data->height);
        i++;
    }
    return (0);
}

int main(void)
{
    t_data    data;

    data.mlx = mlx_init();
    
    data.img = mlx_xpm_file_to_image(data.mlx, "textures/dino.xpm", &data.width, &data.height);
    data.wind = mlx_new_window(data.mlx, 32*data.width, 32*data.height, "huh");
    
    mlx_key_hook(data.wind, handle_input, &data);
    mlx_loop_hook(data.mlx, dinomove, &data);
   
    mlx_loop(data.mlx);
    
}