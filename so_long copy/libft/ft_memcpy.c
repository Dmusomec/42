/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:11:29 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:58:28 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *pegar, const void *copiar, size_t numero)
{
	unsigned char	*p;
	unsigned char	*copi;
	size_t			c;

	p = (unsigned char *)pegar;
	copi = (unsigned char *)copiar;
	c = 0;
	if (!pegar && !copiar)
		return (0);
	while (c < numero)
	{
		p[c] = copi[c];
		c++;
	}
	return (pegar);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	cadena[10] = "pingo";
	char	cadena2[10];
	
	printf("%s\n", cadena);
	printf("%s\n", cadena2);
	
	ft_memcpy(cadena2, cadena, 2);
	
	printf("%s\n", cadena);
	printf("%s\n", cadena2);
	return (0);
}*/