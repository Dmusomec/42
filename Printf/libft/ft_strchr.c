/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:09 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:59:03 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *origen, int car)
{
	while (*origen != '\0')
	{
		if (*origen == (char)car)
			return ((char *)origen);
		origen++;
	}
	if (*origen == (char)car)
		return ((char *)origen);
	return (NULL);
}

/*int main() 
{
    const char *cadena = "Hola, mundo";
    char caracter = 'm';

    char *resultado = strchr(cadena, caracter);

    if (resultado != NULL) {
        printf("'%c' encontrado %ld\n", caracter, resultado - cadena);
    } else {
        printf("'%c' no encontrado.\n", caracter);
    }

    return 0;
}*/