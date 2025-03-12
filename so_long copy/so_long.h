/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:50 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/12 16:38:37 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

typedef struct s_data 
{
	char **map;
	char *line;
	int	i;
	int	fd;
	size_t	height;
	size_t	width;
	int	x;
	int	y;
	int	row;
}	t_data;

# define TILE

#endif