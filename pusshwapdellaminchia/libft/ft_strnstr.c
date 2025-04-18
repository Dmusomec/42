/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:30:27 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/10 18:55:34 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	c;
	size_t	c1;

	c = 0;
	c1 = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[c] != '\0' && c < len)
	{
		if (big[c] == little[0])
		{
			c1 = 0;
			while (c + c1 < len && big[c + c1] == little[c1])
			{
				if (little[c1 + 1] == '\0')
					return ((char *)&big[c]);
				c1++;
			}
		}
		c++;
	}
	return (NULL);
}

//#include <stdio.h>
/*int main() 
{
    const char *haystack = "pingos duros";
    const char *needle = "duro";
    
    char *resultado = fstrnstr(haystack, needle, 12);

    if (resultado != NULL) {
        printf("%s\n", resultado);
    } else {
        printf("subcadena no encontrada.\n");
    }

    return 0;
}*/