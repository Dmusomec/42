/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:22:08 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/12 19:11:01 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(t_data *game)
{
	if (ft_strchr_str(game->line, "01CEP\n") == -1)
		return (-1);
	if (game->width == 0)
		game->width = ft_strlen(game->line);
	if (game->height == 0 && ft_strchr_str(game->line, "1\n") == -1)
		return (-1);
	if (game->line[0] != '1' || ft_strlen(game->line) < 2)
		return (-1);
	if (ft_strlen(game->line) != game->width)
	{
		if (game->line[game->width] == '\0' && ft_strchr_str(game->line, "1\n") != -1)
			return (1);
		else
			return (-1);
	}
	else
		return (1);
}

int	get_size(t_data *game)
{
	game->line = get_next_line(game->fd);
	if (!game->line)
		return (-1);
	if (check_line(game) == -1)
		return (-1);
	game->height++;
	return (1);
}

int	main()
{
	t_data *game = malloc(sizeof(t_data) * 1);
	if (!game)
		return (1);
	game->map = 0;
	game->line = "0";
	game->height = 0;
	game->fd = 0;
	game->i = 0;
	game->fd = open("texto.txt", O_RDONLY);
	while (get_size(game) != -1)
	{
		printf("%s", game->line);
	}
	close(game->fd);
	return 0;
}