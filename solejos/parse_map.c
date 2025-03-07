/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:12:43 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/07 20:15:58 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void parse_map(char *filename, t_game *game)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_exit("Failed to open map file");
    game->rows = 0;
    while ((line = get_next_line(fd)))
    {
        free(line);
        game->rows++;
    }
    close(fd);

    game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
    if (!game->map)
        error_exit("Malloc failed");

    fd = open(filename, O_RDONLY);
    i = 0;
    while (i < game->rows)
    {
        line = get_next_line(fd);
        if (!line)
            error_exit("Map file is shorter than expected");
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        game->map[i++] = line;
    }
    game->map[i] = NULL;
    close(fd);
}

void	validate_map(t_game *game)
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	i;
	int	j;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	game->cols = (int)ft_strlen(game->map[0]);
	for (i = 0; game->map[i]; i++)
	{
		if ((int)ft_strlen(game->map[i]) != game->cols)
			error_exit("Map is not rectangular");
		for (j = 0; j < game->cols; j++)
		{
			if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols - 1)
				if (game->map[i][j] != '1')
					error_exit("Map not surrounded by walls");
			if (game->map[i][j] == 'P' && ++p_count)
				game->player_y = i, game->player_x = j;
			else if (game->map[i][j] == 'E' && ++e_count)
				game->exit_count++;
			else if (game->map[i][j] == 'C')
				c_count++;
			else if (!ft_strchr("01CEP", game->map[i][j]))
				error_exit("Invalid character in map");
		}
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		error_exit("Invalid number of players, exits, or collectibles");
	game->collectibles = c_count;
}