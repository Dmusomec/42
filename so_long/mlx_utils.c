/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:52:15 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/31 14:24:17 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_boot(t_data *g)
{
    g->mlx = mlx_init();
    if (!g->mlx)
        return (-1);
    if (setadress(g) == -1)
    {
        print_error("Textures error", g);
        mlx_destroy_display(g->mlx);
        return (free(g->mlx), -1);
    }
    g->wind = mlx_new_window(g->mlx, g->width * 16, g->height * 17
        ,"So_long");
    if (!g->wind)
        return (print_error("Window Error", g), -1);
    return (0);
}