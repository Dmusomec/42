/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:02:39 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/08 17:20:33 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	print_error(char *msg, t_data *game)
{
	ft_printf("Error\n%s\n", msg);
	if (game)
	{
		free_map(game);
		if (game->fd != -1)
			close(game->fd);
	}
	exit(1);
}

void	print_map(t_data *game)
{
	int	i;

	ft_printf("Map (Height: %d, Width: %d):\n", game->height, game->width);
	i = 0;
	while (i < game->height)
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}

void	print_counts(t_data *game)
{
	ft_printf("Exits (E):    %d\n", game->exit_count);
	ft_printf("Collectibles (C): %d\n", game->collectible_count);
	ft_printf("Players (P):   %d\n", game->player_count);
}
