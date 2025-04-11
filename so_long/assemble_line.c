/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:08:58 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/11 21:03:53 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(t_data *game)
{
	char	*line;

	line = game->line;
	if (check_invalid_chars(line) == -1)
		print_error("Invalid characters in map", game);
	if (!validate_first_line(game, line))
		return (-1);
	if (!validate_length_and_borders(game, line))
		return (-1);
	count_special_chars(game, line);
	return (1);
}

int	setlayer(t_data *game)
{
	char	**temp;
	int		i;

	temp = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!temp)
		return (-1);
	i = -1;
	while (++i < game->height)
		temp[i] = game->map[i];
	temp[game->height] = (char *)malloc((game->width + 1) * sizeof(char));
	if (!temp[game->height])
	{
		free(temp);
		return (-1);
	}
	ft_strlcpy(temp[game->height], game->line, game->width + 1);
	free(game->map);
	game->map = temp;
	free(game->line);
	game->line = NULL;
	return (1);
}

int	get_size(t_data *game)
{
	size_t	len;

	game->line = get_next_line(game->fd);
	if (!game->line)
		return (-1);
	len = ft_strlen(game->line);
	if (len > 0 && game->line[len - 1] == '\n')
		game->line[--len] = '\0';
	if (check_line(game) == -1)
	{
		free(game->line);
		print_error("Error assembling line", game);
		return (-1);
	}
	if (setlayer(game) == -1)
	{
		free(game->line);
		print_error("Error assembling line", game);
		return (-1);
	}
	game->height++;
	return (1);
}

void	validate_counts(t_data *game)
{
	if (game->exit_count < 1)
		print_error("Map must have at least one exit (E).", game);
	if (game->collectible_count < 1)
		print_error("Map must have at least one collectible (C).", game);
	if (game->player_count != 1)
		print_error("Map must have exactly one player (P).", game);
}

void	validate_last_line(t_data *game)
{
	char	*last_line;

	if (game->height < 1)
		return ;
	last_line = game->map[game->height - 1];
	if (!is_all_ones(last_line))
		print_error("Last line must be all walls (1)", game);
}
