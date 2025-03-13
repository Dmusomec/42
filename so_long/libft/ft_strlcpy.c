/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:19:02 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:59:21 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *pegar, const char *copiar, size_t numero)
{
	size_t	largo;
	size_t	c;

	largo = 0;
	c = 0;
	while (copiar[largo] != '\0')
		largo++;
	if (numero > 0)
	{
		while (c < numero - 1 && copiar[c] != '\0')
		{
			pegar[c] = copiar[c];
			c++;
		}
		pegar[c] = '\0';
	}
	return (largo);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	copiar[] = "choto duro";
	char	pegar[6] = "\0";
	
	printf("%s\n", copiar);
	printf("%s\n", pegar);
	
	size_t	resultado = ft_strlcpy(pegar, copiar, sizeof (pegar));
	
	printf("%s\n", pegar);
	printf("%zu\n", resultado);
}*/
