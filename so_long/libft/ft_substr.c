/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:10:14 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 21:27:33 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	c;
	size_t	c2;
	char	*pipo;

	c = 0;
	c2 = ft_strlen(s) - start;
	if (c2 > len)
		c2 = len;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	pipo = ft_calloc(c2 + 1, 1);
	if (!pipo)
		return (NULL);
	while (c < len && c < c2)
	{
		pipo[c] = s[start];
		c++;
		start++;
	}
	pipo[c] = '\0';
	return (pipo);
}
