/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:50 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/04 17:09:32 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <X11/keysymdef.h>
# include <X11/keysym.h>

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <errno.h>

typedef struct s_data 
{
	void	*mlx;
	void	*wind;
	void	*background;
	void	*wall;
	void	*keys;
	void	*player;
	void	*exit;
	char **map;
	char **map_copy;
	char *line;
	int	i;
	int	counter;
	int	fd;
	int	height;
	int	width;
	int	playerx;
	int playery;
	int	x;
	int	y;
	int	row;
	int col;
	int	exit_count;
	int	collectible_count;
	int	player_count;
}	t_data;

int	check_invalid_chars(char *line);
int	is_all_ones(char *line);
int	validate_first_line(t_data *game, char *line);
int	validate_length_and_borders(t_data *game, char *line);
void	count_special_chars(t_data *game, char *line);
int	check_line(t_data *game);
int setlayer(t_data *game);
int get_size(t_data *game);
void    validate_counts(t_data *game);
void	validate_last_line(t_data *game);
void    print_error(char *msg, t_data *game);
void	validate_path(t_data *g);
void    free_map(t_data *game);
void    print_error(char *msg, t_data *game);
void    print_map(t_data *game); //COMENTAR en GEN_UTILS.C
void	print_counts(t_data *game); //COMENTAR en GEN_UTILS.C
void    free_textures(t_data *g);
int setadress(t_data *g);
int mlx_boot(t_data *g);
void    image_to_win(t_data *g);

#endif