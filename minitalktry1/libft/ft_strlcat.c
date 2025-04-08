/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:40:26 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:59:10 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *pegar, const char *copiar, size_t numero)
{
	size_t	pipo;
	size_t	d;
	size_t	pepo;

	pipo = ft_strlen(pegar);
	pepo = ft_strlen(copiar);
	if (numero <= pipo)
		return (numero + pepo);
	d = 0;
	while ((copiar[d] != '\0') && (pipo + d) < numero - 1)
	{
		pegar[pipo + d] = copiar[d];
		d++;
	}
	pegar[pipo + d] = '\0';
	return (pipo + pepo);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	ura[] = "culialeon";
	char	ura2[] = "pingo";

	printf("%s\n", ura2);

	size_t	resultado = ft_strlcat(ura2, ura, 3);
	
	printf("%s\n", ura2);
	printf("%zu\n", resultado);
}*/