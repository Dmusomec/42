/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:09:58 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/28 21:10:45 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_adress(t_data *g)
{
    
}

int setadress(t_data *g)
{
    int height;
    int width;

    height = 0;
    width = 0;
    g->background = mlx_xpm_file_to_image(g->mlx, "./textures/fondo.xpm",
        &height, &width);
    if (!g->background)
        return (print_error("failed to upload image", g), free_adress(g), -1);
    g->wall = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm",
        &height, &width);
    if (!g->wall)
        return (print_error("failed to upload image", g), free_adress(), -1);
    g->player = mlx_xpm_file_to_image(g->mlx, "./textures/player.xpm",
         &height, &width);
    if (!g->player)
        return (print_error("failed to upload image", g), free_adress(), -1);
    g->keys = mlx_xpm_file_to_image(g->mlx, "./textures/llave.xpm",
        &height, &width);
    if (!g->keys)
        return (print_error("failed to upload image", g), free_adress(), -1);
    return (0);
}
