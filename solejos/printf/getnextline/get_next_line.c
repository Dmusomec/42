/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:19:04 by dmusomec          #+#    #+#             */
/*   Updated: 2025/01/25 17:59:55 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ftt_cutit(char *statik)
{
	char	*temp;
	size_t	i;
	size_t	c;

	i = 0;
	while (statik[i] && statik[i] != '\n')
		i++;
	if (statik[i] == '\n')
		i++;
	if (!statik[i])
		return (free(statik), NULL);
	temp = ftt_calloc((ftt_strlen(statik) - i) + 1, sizeof(char));
	if (temp == NULL)
		return (free(statik), NULL);
	c = 0;
	while (statik[i])
		temp[c++] = statik[i++];
	return (free(statik), temp);
}

char	*givememyline(char *statik)
{
	char	*line;
	size_t	i;
	size_t	c;

	i = 0;
	while (statik[i] != '\0' && statik[i] != '\n')
		i++;
	if (statik[i] == '\n')
		i++;
	line = ftt_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	c = 0;
	while (c < i)
	{
		line[c] = statik[c];
		c++;
	}
	if (statik[i] == '\n')
		line[c] = '\n';
	line[c++] = '\0';
	return (line);
}

char	*readline(int fd, char *statik)
{
	ssize_t	bread;
	char	*addthis;

	if (!statik)
		statik = ftt_calloc(1, sizeof(char));
	addthis = ftt_calloc(BUFFER_SIZE + 1, sizeof(char));
	bread = 1;
	while (!ftt_strchr(statik, '\n') && bread > 0)
	{
		bread = read(fd, addthis, BUFFER_SIZE);
		if (bread == -1)
			return (free(statik), free(addthis), NULL);
		addthis[bread] = '\0';
		statik = ftt_strjoin(statik, addthis);
	}
	if (bread == 0 && statik[0] == '\0')
		return (free(addthis), free(statik), NULL);
	return (free(addthis), statik);
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	statik = readline(fd, statik);
	if (!statik)
		return (NULL);
	line = givememyline(statik);
	if (!line)
		return (NULL);
	statik = ftt_cutit(statik);
	return (line);
}

// int	main()
// {
//     int fd;
//     char *line;

//     fd = open("texto.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error al abrir el archivo");
//         return 1;
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }