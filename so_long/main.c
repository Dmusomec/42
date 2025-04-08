/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:46:02 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/08 17:59:14 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber_file(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

void	huh(t_data *g)
{
	validate_counts(g);
	validate_last_line(g);
	validate_path(g);
	print_map(g);
	print_counts(g);
	mlx_boot(g);
	setadress(g);
	image_to_win(g);
	image_to_winb(g);
}

int	main(int argc, char **argv)
{
	t_data	game;

	game.mlx = NULL;
	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./solong <map_file.ber>\n");
		return (1);
	}
	if (!is_ber_file(argv[1]))
	{
		ft_printf("Error\nMap file must have .ber extension\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_data));
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		print_error("Failed to open file.", &game);
	while (1)
		if (get_size(&game) == -1)
			break ;
	if (game.height == 0 || game.width == 0)
		print_error("Map is empty or invalid.", &game);
	huh(&game);
	mlx_loop(game.mlx);
	return (0);
}
