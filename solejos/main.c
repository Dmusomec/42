/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:22:30 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/07 20:37:44 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
        error_exit("Usage: ./so_long <map.ber>");
    parse_map(argv[1], &game);
    validate_map(&game);
    init_game(&game);
    render_map(&game);
    mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, exit_game, &game);
    mlx_loop(game.mlx);
    return (0);
}