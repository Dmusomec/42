/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:26:59 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 19:34:07 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			co;
	unsigned char	*sa;
	unsigned char	ca;

	co = 0;
	sa = (unsigned char *)s;
	ca = (unsigned char)c;
	while (co < n)
	{
		if (sa[co] == ca)
			return ((void *)(sa + co));
		co++;
	}
	return (NULL);
}

//#include <stdio.h>

/*int main() 
{
    char bloque[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    char byte = 'd';

    char *resultado = fmemchr(bloque, byte, sizeof(bloque));

    if (resultado != NULL)
        printf("'%c' %ld\n", byte, resultado - bloque);
    else
        printf("Byte '%c' no encontrado.\n", byte);

    return 0;
}*/