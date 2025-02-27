/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:51:41 by dmusomec          #+#    #+#             */
/*   Updated: 2025/02/12 14:07:28 by dmusomec         ###   ########.fr       */
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

// #include <stdio.h>
// #include <string.h>

// void print_split_result(char **split)
// {
//     if (!split)
//     {
//         printf("(null)\n");
//         return;
//     }
    
//     printf("[");
//     for (int i = 0; split[i]; i++)
//     {
//         printf("\"%s\"", split[i]);
//         if (split[i + 1])
//             printf(", ");
//     }
//     printf("]\n");
// }

// char *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     size_t    i;
//     char    *sub;
    
//     if (!s)
//         return (NULL);
//     if (start >= (unsigned int)strlen(s))
//         return (strdup(""));
//     if (len > strlen(s + start))
//         len = strlen(s + start);
//     sub = malloc(len + 1);
//     if (!sub)
//         return (NULL);
//     i = 0;
//     while (i < len)
//     {
//         sub[i] = s[start + i];
//         i++;
//     }
//     sub[i] = '\0';
//     return (sub);
// }


// int main(void)
// {
//     char **result;
    
//     Test 1: Normal case
//     result = ft_split("Hello world this is a test", ' ');
//     printf("Test 1: ");
//     print_split_result(result);
//     ft_free(result);

//     Test 2: String with multiple separators
//     result = ft_split("   multiple   separators   ", ' ');
//     printf("Test 2: ");
//     print_split_result(result);
//     ft_free(result);

//     Test 3: No separators
//     result = ft_split("NoSeparatorsHere", ' ');
//     printf("Test 3: ");
//     print_split_result(result);
//     ft_free(result);

//     Test 4: Empty string
//     result = ft_split("", ' ');
//     printf("Test 4: ");
//     print_split_result(result);
//     ft_free(result);

//     Test 5: NULL input
//     result = ft_split(NULL, ' ');
//     printf("Test 5: ");
//     print_split_result(result);

//     Test 6: Different separator
//     result = ft_split("apple,banana,cherry", ',');
//     printf("Test 6: ");
//     print_split_result(result);
//     ft_free(result);

//     return 0;
// }