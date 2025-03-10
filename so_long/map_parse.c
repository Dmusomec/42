/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:22:08 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/10 17:15:33 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	if (ft_strchr_str(line, "01CEP") == -1)
		return (-1);
	if (ft_strlen(line) < 2)
		return (-1);
	else
		return (1);
}

int	get_map(char *mapname)
{
	int		fd;
	char	*line;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_line(line) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}

	close(fd);
	return (1);
}

int	main()
{
	
	if (check_line("0001111l") == -1)
		printf("mala\n");
	if (check_line("0001111") == 1)
		printf("buena\n");
	if (get_map("texto.txt") == 1)
		printf("god\n");
	if (get_map("texto.txt") == -1)
		printf("godnt\n");
	
	return 0;
}