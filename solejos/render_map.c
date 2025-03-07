/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:19:08 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/07 20:19:28 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx, game->win);
	for (i = 0; i < game->rows; i++)
	{
		for (j = 0; j < game->cols; j++)
		{
			void	*img;
			if (game->map[i][j] == '1')
				img = game->wall.img;
			else if (game->map[i][j] == 'C')
				img = game->collectible.img;
			else if (game->map[i][j] == 'E')
				img = game->exit.img;
			else
				img = game->floor.img;
			mlx_put_image_to_window(game->mlx, game->win, img, j * TILE_SIZE,
				i * TILE_SIZE);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}