/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:27:08 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/10 16:46:36 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nueva;
	unsigned int	c;

	nueva = ft_calloc(ft_strlen(s) + 1, 1);
	if (!nueva)
		return (NULL);
	c = 0;
	while (s[c] != '\0')
	{
		nueva[c] = f(c, s[c]);
		c++;
	}
	return (nueva);
}
