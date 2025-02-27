/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:33:23 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:58:13 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			c;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	c = 0;
	if (n == 0)
		return (0);
	while (c < n)
	{
		if (a[c] != b[c])
			return (a[c] - b[c]);
		c++;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	const char *s1 = "ab";
	const char *s2 = "ac";

	int resultado = fmemcmp(s1, s2, 2);
	int resultado2 = memcmp(s1, s2, 2);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%d\n", resultado);
	printf("%d\n", resultado2);

	char bloque1[] = { 'a', 'b'};
    char bloque2[] = { 'a', 'b'};

    int resultado3 = fmemcmp(bloque1, bloque2, 2);

    if (resultado3 == 0) {
        printf("Los primeros bytes son iguales.\n");
    } else {
        printf("Los primeros bytes son diferentes.\n");
    }

	return (0);
}*/