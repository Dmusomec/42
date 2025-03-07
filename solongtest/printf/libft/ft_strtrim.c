/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:38:33 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/10 15:58:31 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inicio;
	size_t	fin;
	char	*temporal;

	if (!s1 || !set)
		return (NULL);
	inicio = 0;
	fin = ft_strlen(s1);
	while (ft_strchr(set, s1[inicio]) && s1[inicio] != '\0')
		inicio++;
	while (ft_strchr(set, s1[fin - 1]) && fin > inicio)
		fin--;
	temporal = ft_substr(s1, inicio, fin - inicio);
	return (temporal);
}
