/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:24:48 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:59:35 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && *s1 && *s2 && (c < n - 1))
	{
		s1++;
		s2++;
		c++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*#include <string.h>
int	main()
{
	const char *s1 = "atoms\0\0\0\0";
	const char *s2 = "atoms\0abc";

	int resultado = ft_strncmp(s1, s2, 6);
	int resultado2 = strncmp(s1, s2, 6);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%d\n", resultado);
	printf("%d\n", resultado2);

	return (0);
}*/