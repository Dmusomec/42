/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:18:19 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/07 20:32:20 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error_exit("MLX initialization failed");

    int screen_width, screen_height;
    mlx_get_screen_size(game->mlx, &screen_width, &screen_height);

    int win_width = game->cols * TILE_SIZE;
    int win_height = game->rows * TILE_SIZE;
    int pos_x = (screen_width - win_width) / 2;
    int pos_y = (screen_height - win_height) / 2;

    game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
    if (!game->win)
        error_exit("Window creation failed");
    
    mlx_do_key_autorepeaton(game->mlx);
    load_textures(game);
}

void	load_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->floor.width, &game->floor.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->exit.width, &game->exit.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->player.width, &game->player.height);
	if (!game->wall.img || !game->floor.img || !game->collectible.img
		|| !game->exit.img || !game->player.img)
		error_exit("Failed to load textures");
}