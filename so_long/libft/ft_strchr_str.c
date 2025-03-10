/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:48:11 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/10 14:23:58 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <unistd.h>

int	ft_strchr_str(const char *str, const char *allow)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tru;

	i = 0;
	tru = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != allow[j] && allow[j] != '\0')
		{
			tru = 1;
			j++;
		}
		if (str[i] == allow[j])
			tru = 0;
		if (tru == 1)
			return (-1);
		i++;
	}
	return (1);
}

// int main(int argc, char **argv)
// {
// 	int a = ft_strchr_str("0001  111PPP", "01P");
// 	printf("%d", a);
// }