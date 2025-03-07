/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:25:09 by dmusomec          #+#    #+#             */
/*   Updated: 2025/01/25 17:59:07 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20

# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

char	*ftt_cutit(char *statik);
char	*givememyline(char *statik);
char	*readline(int fd, char *statik);
char	*get_next_line(int fd);
size_t	ftt_strlen(const char *s);
void	*ftt_calloc(size_t nmb, size_t size);
char	*ftt_strchr(const char *origen, int car);
char	*ftt_strjoin(char *s1, char *s2);

#endif