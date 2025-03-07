/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:07:00 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/07 20:33:15 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define TILE_SIZE 32
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		exit_count;
	int		player_x;
	int		player_y;
	int		moves;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
	t_img	player;
}	t_game;

void	parse_map(char *filename, t_game *game);
void	validate_map(t_game *game);
void	init_game(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	exit_game(t_game *game);
void	exit_game_win(t_game *game);
void	error_exit(char *msg);

#endif