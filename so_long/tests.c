/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:22:08 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/04 21:51:03 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// int	check_line(t_data *game)
// {
// 	if (ft_strchr_str(game->line, "01CEP\n") == -1)
// 		return (-1);
// 	if (game->width == 0)
// 	{
// 		game->width = ft_strlen(game->line);
// 		game->i = game->width - 2;
// 	}
// 	if (game->height == 0 && ft_strchr_str(game->line, "1\n") == -1)
// 		return (-1);
// 	if (game->line[0] != '1' || ft_strlen(game->line) < 2)
// 		return (-1);
// 	if (game->line[game->i] != '1')
// 		return (-1);
// 	if (ft_strlen(game->line) != game->width)
// 	{
// 		if (game->line[game->width] == '\0' && ft_strchr_str(game->line, "1\n") != -1)
// 			return (1);
// 		else
// 			return (-1);
// 	}
// 	else
// 		return (1);
// }

// int setlayer(t_data *game)
// {
// 	game->map[game->height] = malloc((game->width + 1) * sizeof(char));
//     if (!game->map[game->height])
// 	{
//         free(game->line);
//         return -1;
//     }
//     ft_strlcpy(game->map[game->height], game->line, game->width + 1);
//     free(game->line);
//     return 1;
// }

// int	get_size(t_data *game)
// {
// 	game->line = get_next_line(game->fd);
// 	if (!game->line)
// 		return (-1);
// 	if (check_line(game) == -1)
// 		return (-1);
// 	if (setlayer(game) == -1)
// 		return(-1);
// 	game->height++;
// 	return (1);
// }

// int	main()
// {
// 	t_data *game = malloc(sizeof(t_data) * 1);
// 	if (!game)
// 		return (1);
// 	game->map = malloc(10 * sizeof(char *));
// 	if (!game->map)
// 		{
// 			close(game->fd);
// 			free(game);
// 			printf("Error: Memory allocation failed.\n");
// 			return 1;
// 		}	
// 	game->line = "0";
// 	game->height = 0;
// 	game->width = 0;
// 	game->fd = 0;
// 	game->i = 0;
// 	game->fd = open("texto.txt", O_RDONLY);
// 	while (get_size(game) != -1)
// 	{
// 		printf("%d", game->height);
// 		printf("%s", game->map[game->height]);
// 	}
//     close(game->fd);
// 	free(game);
// 	return 0;
// }

#include "so_long.h"

// void    free_map(t_data *game)
// {
//     int  i;

//     if (game->map)
//     {
//         i = 0;
//         while (i < game->height)
//         {
//             if (game->map[i])
//                 free(game->map[i]);
//             i++;
//         }
//         free(game->map);
//         game->map = NULL;
//     }
// }

// void    print_error(char *msg, t_data *game)
// {
//     ft_printf("Error\n%s\n", msg);
//     if (game)
//     {
//         free_map(game);
//         if (game->fd != -1)
//             close(game->fd);
//     }
//     exit(1);
// }

// static void	copy_map(t_data *g)
// {
// 	int	i;

// 	g->map_copy = (char **)malloc(sizeof(char *) * g->height);
// 	if (!g->map_copy)
// 		print_error("Malloc failed", g);
// 	i = -1;
// 	while (++i < g->height)
// 	{
// 		g->map_copy[i] = ft_strdup(g->map[i]);
// 		if (!g->map_copy[i])
// 		{
// 			while (i-- > 0)
// 				free(g->map_copy[i]);
// 			free(g->map_copy);
// 			print_error("Map copy failed", g);
// 		}
// 	}
// }

// static void	flood_fill(t_data *g, int x, int y)
// {
// 	if (x < 0 || y < 0 || x >= g->width || y >= g->height 
// 		|| g->map_copy[y][x] == '1' || g->map_copy[y][x] == 'X')
// 		return ;

// 	if (g->map_copy[y][x] == 'C')
// 		g->collectible_count--;
// 	if (g->map_copy[y][x] == 'E')
// 		g->exit_count--;

// 	g->map_copy[y][x] = 'X'; // Mark as visited
// 	flood_fill(g, x + 1, y); // Right
// 	flood_fill(g, x - 1, y); // Left
// 	flood_fill(g, x, y + 1); // Down
// 	flood_fill(g, x, y - 1); // Up
// }

// static void	find_player(t_data *g)
// {
// 	g->y = -1;
// 	while (++g->y < g->height)
// 	{
// 		g->x = -1;
// 		while (++g->x < g->width)
// 			if (g->map[g->y][g->x] == 'P')
// 				return ;
// 	}
// 	print_error("Player not found", g);
// }

// void	free_map_copy(t_data *g)
// {
// 	int	i;

// 	if (g->map_copy)
// 	{
// 		i = -1;
// 		while (++i < g->height)
// 			free(g->map_copy[i]);
// 		free(g->map_copy);
// 		g->map_copy = NULL;
// 	}
// }

// void	validate_path(t_data *g)
// {
// 	int	orig_c = g->collectible_count;
// 	int	orig_e = g->exit_count;

// 	copy_map(g); // Copy original map
// 	find_player(g);
// 	flood_fill(g, g->x, g->y);
// 	if (g->collectible_count != 0 || g->exit_count != 0)
// 		print_error("Unreachable collectibles/exit", g);
// 	g->collectible_count = orig_c; // Restore original counts
// 	g->exit_count = orig_e;
// 	free_map_copy(g); // Cleanup
// }

// static int check_invalid_chars(char *line)
// {
//     while (*line)
//     {
//         if (!ft_strchr("01CEP", *line))
//             return (-1);
//         line++;
//     }
//     return (0);
// }

// static int is_all_ones(char *line)
// {
//     while (*line)
//     {
//         if (*line != '1')
//             return (0);
//         line++;
//     }
//     return (1);
// }

// static int	validate_first_line(t_data *game, char *line)
// {
// 	if (game->height == 0 && !is_all_ones(line))
// 	{
// 		print_error("First line must be all walls (1)", game);
// 		return (0);
// 	}
// 	return (1);
// }

// static int	validate_length_and_borders(t_data *game, char *line)
// {
// 	size_t	len;

// 	len = ft_strlen(line);
// 	if (game->width == 0)
// 	{
// 		game->width = len;
// 		game->i = len - 1;
// 	}
// 	if (len != game->width)
// 	{
// 		print_error("Map is not rectangular", game);
// 		return (0);
// 	}
// 	if (line[0] != '1' || line[game->i] != '1')
// 	{
// 		print_error("Map borders must be walls (1)", game);
// 		return (0);
// 	}
// 	return (1);
// }

// static void	count_special_chars(t_data *game, char *line)
// {
// 	while (*line)
// 	{
// 		if (*line == 'E')
// 			game->exit_count++;
// 		else if (*line == 'C')
// 			game->collectible_count++;
// 		else if (*line == 'P')
// 			game->player_count++;
// 		line++;
// 	}
// }

// int	check_line(t_data *game)
// {
// 	char	*line;

// 	line = game->line;
// 	if (check_invalid_chars(line) == -1)
// 		print_error("Invalid characters in map", game);
// 	if (!validate_first_line(game, line))
// 		return (0);
// 	if (!validate_length_and_borders(game, line))
// 		return (0);
// 	count_special_chars(game, line);
// 	return (1);
// }

// int setlayer(t_data *game)
// {
//     char    **temp;
//     int     i;

//     temp = (char **)malloc((game->height + 1) * sizeof(char *));
//     if (!temp)
//         return (-1);

//     i = -1;
//     while (++i < game->height)
//         temp[i] = game->map[i];

//     temp[game->height] = (char *)malloc((game->width + 1) * sizeof(char));
//     if (!temp[game->height])
//     {
//         free(temp);
//         return (-1);
//     }
//     ft_strlcpy(temp[game->height], game->line, game->width + 1);

//     free(game->map);
//     game->map = temp;

//     free(game->line);
//     game->line = NULL;
//     return (1);
// }

// int get_size(t_data *game)
// {
//     size_t  len;

//     game->line = get_next_line(game->fd);
//     if (!game->line)
//         return (-1);
//     len = ft_strlen(game->line);
//     if (len > 0 && game->line[len - 1] == '\n')
//         game->line[--len] = '\0';
//     if (check_line(game) == -1)
//         return (-1);
//     if (setlayer(game) == -1)
//     {
//         free(game->line);
//         return (-1);
//     }
//     game->height++;
//     return (1);
// }

// void    validate_counts(t_data *game)
// {
//     if (game->exit_count < 1)
//         print_error("Map must have at least one exit (E).", game);
//     if (game->collectible_count < 1)
//         print_error("Map must have at least one collectible (C).", game);
//     if (game->player_count != 1)
//         print_error("Map must have exactly one player (P).", game);
// }

// void    print_map(t_data *game)
// {
//     int  i;

//     ft_printf("Map (Height: %d, Width: %d):\n", game->height, game->width);
//     i = 0;
//     while (i < game->height)
//     {
//         ft_printf("%s\n", game->map[i]);
//         i++;
//     }
// }

// void	print_counts(t_data *game)
// {
// 	ft_printf("Exits (E):    %d\n", game->exit_count);
// 	ft_printf("Collectibles (C): %d\n", game->collectible_count);
// 	ft_printf("Players (P):   %d\n", game->player_count);
// }

// static void	validate_last_line(t_data *game)
// {
// 	char	*last_line;

// 	if (game->height < 1)
// 		return ;
// 	last_line = game->map[game->height - 1];
// 	if (!is_all_ones(last_line))
// 		print_error("Last line must be all walls (1)", game);
// }

int	main(int argc, char **argv)
{
	t_data	game;

	game.mlx = NULL;
	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./solong <map_file.ber>\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_data));
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		print_error("Failed to open file.", &game);
	while (1)
	{
		if (get_size(&game) == -1)
			break ;
	}
	if (game.height == 0 || game.width == 0)
		print_error("Map is empty or invalid.", &game);
	validate_counts(&game);
    validate_last_line(&game);
    validate_path(&game);
	print_map(&game);
	print_counts(&game);
	mlx_boot(&game);
    setadress(&game);
    image_to_win(&game);
    mlx_loop(game.mlx);
	return (0);
}
