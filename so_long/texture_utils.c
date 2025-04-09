/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:09:58 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/09 11:20:17 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_data *g)
{
	if (g->mlx)
	{
		if (g->player)
			mlx_destroy_image(g->mlx, g->player);
		if (g->background)
			mlx_destroy_image(g->mlx, g->background);
		if (g->keys)
			mlx_destroy_image(g->mlx, g->keys);
		if (g->wall)
			mlx_destroy_image(g->mlx, g->wall);
		if (g->exit)
			mlx_destroy_image(g->mlx, g->exit);
	}
}

int	setadress(t_data *g)
{
	g->heightb = 0;
	g->widthb = 0;
	g->background = mlx_xpm_file_to_image(g->mlx, "./textures/fondo.xpm",
			&g->heightb, &g->widthb);
	if (!g->background)
		return (print_error("failed to upload image", g), -1);
	g->wall = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm",
			&g->heightb, &g->widthb);
	if (!g->wall)
		return (print_error("failed to upload image", g), -1);
	g->player = mlx_xpm_file_to_image(g->mlx, "./textures/player.xpm",
			&g->heightb, &g->widthb);
	if (!g->player)
		return (print_error("failed to upload image", g), -1);
	g->keys = mlx_xpm_file_to_image(g->mlx, "./textures/llave.xpm",
			&g->heightb, &g->widthb);
	if (!g->keys)
		return (print_error("failed to upload image", g), -1);
	g->exit = mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm",
			&g->heightb, &g->widthb);
	if (!g->exit)
		return (print_error("failed to upload image", g), -1);
	return (0);
}

void	image_to_win(t_data *g)
{
	g->i = 0;
	g->row = 0;
	while (g->i < g->height && g->map[g->i])
	{
		g->counter = 0;
		g->col = 0;
		while (g->counter < g->width && g->map[g->i][g->counter])
		{
			if (g->map[g->i][g->counter] == '0')
				mlx_put_image_to_window(g->mlx, g->wind,
					g->background, g->col, g->row);
			if (g->map[g->i][g->counter] == '1')
				mlx_put_image_to_window(g->mlx, g->wind,
					g->wall, g->col, g->row);
			g->col += 16;
			g->counter++;
		}
		g->row += 17;
		g->i++;
	}
}

void	image_to_winb(t_data *g)
{
	g->i = 0;
	g->row = 0;
	while (g->i < g->height && g->map[g->i])
	{
		g->counter = 0;
		g->col = 0;
		while (g->counter < g->width && g->map[g->i][g->counter])
		{
			if (g->map[g->i][g->counter] == 'C')
				mlx_put_image_to_window(g->mlx, g->wind,
					g->keys, g->col, g->row);
			if (g->map[g->i][g->counter] == 'E')
				mlx_put_image_to_window(g->mlx, g->wind,
					g->exit, g->col, g->row);
			if (g->map[g->i][g->counter] == 'P')
				mlx_put_image_to_window(g->mlx, g->wind,
					g->player, g->col, g->row);
			g->col += 16;
			g->counter++;
		}
		g->row += 17;
		g->i++;
	}
}

void	redraw_game(t_data *g, int newx, int newy)
{
	mlx_put_image_to_window(g->mlx, g->wind, g->background,
		g->playerx * 16, g->playery * 17);
	mlx_put_image_to_window(g->mlx, g->wind, g->player,
		newx * 16, newy * 17);
}
