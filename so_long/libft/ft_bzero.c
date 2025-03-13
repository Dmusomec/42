/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:56:03 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:57:16 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *puntero, size_t numero)
{
	unsigned char	*p;
	size_t			c;

	p = (unsigned char *)puntero;
	c = 0;
	while (c < numero)
	{
		p[c] = '\0';
		c++;
	}
}

/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	cadena[10] = "pingo";
	printf("%s\n", cadena);
	ft_bzero(cadena, 1);
	printf("%s\n", cadena);
	return (0);
}*/