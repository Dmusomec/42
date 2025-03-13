/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:09:59 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:58:52 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *puntero, int valor, size_t numero)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			c;

	p = (unsigned char *)puntero;
	v = (unsigned char)valor;
	c = 0;
	while (c != numero)
	{
		p[c] = v;
		c++;
	}
	return (puntero);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	cadena[10];
	ft_memset(cadena, 88, 2);
	
	printf("%s\n", cadena);
	return (0);
}*/