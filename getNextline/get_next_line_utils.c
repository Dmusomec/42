/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:00 by dmusomec          #+#    #+#             */
/*   Updated: 2025/01/25 18:36:17 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	len2;
	size_t	c;
	char	*nueva;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	c = 0;
	nueva = ft_calloc(len + len2 + 1, 1);
	if (!nueva)
		return (NULL);
	while (s1 && s1[c] != '\0')
	{
		*nueva = s1[c];
		nueva++;
		c++;
	}
	c = 0;
	while (s1 && s2[c] != '\0')
	{
		*nueva = s2[c];
		nueva++;
		c++;
	}
	return (free(s1), nueva - (len + len2));
}

char	*ft_strchr(const char *origen, int car)
{
	while (*origen != '\0')
	{
		if (*origen == (char)car)
			return ((char *)origen);
		origen++;
	}
	if (*origen == (char)car)
		return ((char *)origen);
	return (NULL);
}

void	*ft_calloc(size_t nmb, size_t size)
{
	unsigned char	*res;
	size_t			i;
	void			*mem;

	i = 0;
	mem = (void *)malloc(nmb * size);
	if (!mem)
		return (NULL);
	res = (unsigned char *)mem;
	while (i < nmb * size)
		res[i++] = 0;
	return (mem);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}
