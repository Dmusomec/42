/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:03:14 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 18:59:51 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*resultado;

	resultado = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			resultado = (char *)s;
		s++;
	}
	if (*s == (char)c)
		resultado = (char *)s;
	return (resultado);
}

/*#include <stdio.h>

int main() {
    const char *cadena = "pingo peludo peludo";
    char *resultado;

    resultado = strrchr(cadena, 'o');

    if (resultado != NULL) {
        printf("pos: %ld\n", resultado - cadena);
    } else {
        printf("no\n");
    }

    return 0;
}*/