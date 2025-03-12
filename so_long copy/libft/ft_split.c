/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:51:41 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/10 14:27:27 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	npalabras;
	int	semaforo;
	int	i;

	npalabras = 0;
	semaforo = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !semaforo)
		{
			semaforo = 1;
			npalabras++;
		}
		else if (s[i] == c)
			semaforo = 0;
		i++;
	}
	return (npalabras);
}

static void	*ft_free(char **t)
{
	int	i;

	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
	return (NULL);
}

static char	**ft_split_mechanic(char const *s, char **t, char c, int npalabras)
{
	int	i;
	int	start;
	int	w;

	i = 0;
	start = 0;
	w = 0;
	while (s[i] && npalabras--)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		t[w++] = ft_substr(s, start, (i - start));
		if (!t[w - 1])
			return (ft_free(t));
		i++;
	}
	t[w] = NULL;
	return (t);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		npalabras;

	if (!s)
		return (NULL);
	npalabras = ft_count_words (s, c);
	t = (char **)malloc((npalabras + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	t = ft_split_mechanic(s, t, c, npalabras);
	return (t);
}
