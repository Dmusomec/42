/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:23:43 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:58:39 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *pegar, const void *copiar, size_t numero)
{
	unsigned char		*pega;
	const unsigned char	*copia;
	size_t				c;

	if (!pegar && !copiar)
		return (NULL);
	pega = (unsigned char *)pegar;
	copia = (const unsigned char *)copiar;
	if (pega > copia)
	{
		c = numero;
		while (c--)
			pega[c] = copia[c];
	}
	else
	{
		c = 0;
		while (c < numero)
		{
			pega[c] = copia[c];
			c++;
		}
	}
	return (pegar);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	cadena[] = "pingo duro";
	char	cadena2[] = "pingo duro";
	
	printf("%s\n", cadena);
	printf("%s\n", cadena2);
	
	ft_memmove(cadena2, cadena + 6, 4);
	
	printf("%s\n", cadena);
	printf("%s\n", cadena2);
	return (0);
}*/