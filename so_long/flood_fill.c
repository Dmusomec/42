/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:55:51 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/04 21:24:09 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(t_data *g)
{
	int	i;

	g->map_copy = (char **)malloc(sizeof(char *) * g->height);
	if (!g->map_copy)
		print_error("Malloc failed", g);
	i = -1;
	while (++i < g->height)
	{
		g->map_copy[i] = ft_strdup(g->map[i]);
		if (!g->map_copy[i])
		{
			while (i-- > 0)
				free(g->map_copy[i]);
			free(g->map_copy);
			print_error("Map copy failed", g);
		}
	}
}

static void	flood_fill(t_data *g, int x, int y)
{
	if (x < 0 || y < 0 || x >= g->width || y >= g->height 
		|| g->map_copy[y][x] == '1' || g->map_copy[y][x] == 'X')
		return ;

	if (g->map_copy[y][x] == 'C')
		g->collectible_count--;
	if (g->map_copy[y][x] == 'E')
		g->exit_count--;

	g->map_copy[y][x] = 'X';
	flood_fill(g, x + 1, y);    //Acordate que TODOS los stacks hacen este proceso.
	flood_fill(g, x - 1, y);
	flood_fill(g, x, y + 1);
	flood_fill(g, x, y - 1);
}

static void	find_player(t_data *g)
{
	g->y = -1;
	while (++g->y < g->height)
	{
		g->x = -1;
		while (++g->x < g->width)
			if (g->map[g->y][g->x] == 'P')
			{
				g->playerx = g->x;
				g->playery = g->y;
				return ;
			}
	}
	print_error("Player not found", g);
}

static void	free_map_copy(t_data *g)
{
	int i;

    if (g->map_copy) 
	{
        i = -1;
        while (++i < g->height)
            free(g->map_copy[i]);
        free(g->map_copy);
        g->map_copy = NULL;
    }
}

void	validate_path(t_data *g)
{
	int	orig_c = g->collectible_count;
	int	orig_e = g->exit_count;

	copy_map(g); // Copy original map
	find_player(g);
	flood_fill(g, g->x, g->y);
	if (g->collectible_count != 0 || g->exit_count != 0)
		print_error("Unreachable collectibles/exit", g);
	g->collectible_count = orig_c; // Restore original counts
	g->exit_count = orig_e;
	free_map_copy(g);
}
