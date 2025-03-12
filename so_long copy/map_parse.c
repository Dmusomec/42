/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:22:08 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/12 17:18:39 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	if (ft_strchr_str(line, "01CEP") == -1)
		return (-1);
	else
		return (1);
}

int	get_size(t_data *game)
{
	game->line = get_next_line(game->fd);
	if (!game->line)
		return (-1);
	if (game->width == 0)
		game->width = ft_strlen(game->line);
	if (ft_strlen(game->line) != game->width || ft_strlen(game->line) < 2)
		return (-1);
	game->height++;
}

int	main()
{
	t_data *game = malloc(sizeof(t_data) * 1);
	if (!game)
		return (1);
	int i = 0;
	game->map = 0;
	game->line = "0";
	game->fd = 0;
	game->i = 0;
	game->fd = open("texto.txt", O_RDONLY);
	if (check_line("000111l") == -1)
		printf("mala\n");
	if (check_line("0000111PPPEEE") == 1)
		printf("buena\n");
	while (get_size(game) != -1)
	{
		printf("%s", game->line);

	}
	close(game->fd);
	return 0;
}