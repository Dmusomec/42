/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:31:38 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/10 12:21:43 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
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
	while (s1[c] != '\0')
	{
		*nueva = s1[c];
		nueva++;
		c++;
	}
	c = 0;
	while (s2[c] != '\0')
	{
		*nueva = s2[c];
		nueva++;
		c++;
	}
	return (nueva - (len + len2));
}
