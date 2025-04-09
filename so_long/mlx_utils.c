/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:52:15 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/09 11:18:01 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_data *g, int newx, int newy)
{
	if (newx < 0 || newx >= g->width || newy < 0 || newy >= g->height)
		return (0);
	if (g->map[newy][newx] == '1')
		return (0);
	return (1);
}

void	update_player_position(t_data *g, int newx, int newy)
{
	if (g->map[newy][newx] == 'C')
	{
		g->collectible_count--;
		g->map[newy][newx] = '0';
	}
	if (g->map[newy][newx] == 'E')
	{
		if (g->collectible_count == 0)
		{
			ft_printf("You win! Moves: %d\n", ++g->move_count);
			ftclose(g);
		}
		return ;
	}
	g->map[g->playery][g->playerx] = '0';
	redraw_game(g, newx, newy);
	g->playerx = newx;
	g->playery = newy;
	g->map[newy][newx] = 'P';
	g->move_count++;
	ft_printf("Moves: %d\n", g->move_count);
}

int	handle_keypress(int keycode, t_data *g)
{
	int	newx;
	int	newy;

	newx = g->playerx;
	newy = g->playery;
	if (keycode == XK_w || keycode == XK_Up)
		newy--;
	else if (keycode == XK_s || keycode == XK_Down)
		newy++;
	else if (keycode == XK_a || keycode == XK_Left)
		newx--;
	else if (keycode == XK_d || keycode == XK_Right)
		newx++;
	else if (keycode == XK_Escape)
		ftclose(g);
	else
		return (0);
	if (is_valid_move(g, newx, newy) == 1)
		update_player_position(g, newx, newy);
	return (0);
}

int	ftclose(t_data *g)
{
	if (g->fd != -1)
		close(g->fd);
	free_map(g);
	free_textures(g);
	if (g->wind)
	{
		mlx_destroy_window(g->mlx, g->wind);
		g->wind = NULL;
	}
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
	exit(0);
}

int	mlx_boot(t_data *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (-1);
	g->wind = mlx_new_window(g->mlx, g->width * 16, g->height * 17,
			"So_long");
	if (!g->wind)
	{
		free(g->mlx);
		return (-1);
	}
	if (setadress(g) == -1)
	{
		print_error("Textures error", g);
		mlx_destroy_display(g->mlx);
		return (free(g->mlx), -1);
	}
	mlx_hook(g->wind, KeyPress, KeyPressMask, handle_keypress, g);
	mlx_hook(g->wind, DestroyNotify, StructureNotifyMask, ftclose, g);
	return (0);
}
