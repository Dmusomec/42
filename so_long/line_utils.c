/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:02 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/28 18:51:51 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_invalid_chars(char *line)
{
    while (*line)
    {
        if (!ft_strchr("01CEP", *line))
            return (-1);
        line++;
    }
    return (0);
}

int is_all_ones(char *line)
{
    while (*line)
    {
        if (*line != '1')
            return (0);
        line++;
    }
    return (1);
}

int	validate_first_line(t_data *game, char *line)
{
	if (game->height == 0 && !is_all_ones(line))
	{
		print_error("First line must be all walls (1)", game);
		return (0);
	}
	return (1);
}

int	validate_length_and_borders(t_data *game, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (game->width == 0)
	{
		game->width = len;
		game->i = len - 1;
	}
	if (len != game->width)
	{
		print_error("Map is not rectangular", game);
		return (0);
	}
	if (line[0] != '1' || line[game->i] != '1')
	{
		print_error("Map borders must be walls (1)", game);
		return (0);
	}
	return (1);
}

void	count_special_chars(t_data *game, char *line)
{
	while (*line)
	{
		if (*line == 'E')
			game->exit_count++;
		else if (*line == 'C')
			game->collectible_count++;
		else if (*line == 'P')
			game->player_count++;
		line++;
	}
}