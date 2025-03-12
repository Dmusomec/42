/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:31:22 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/10 16:26:51 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intl(int n)
{
	int	c;

	c = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = (n / 10);
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*x;
	int		c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	c = intl(n);
	if (n < 0)
		c++;
	x = ft_calloc((c + 1), 1);
	if (!x)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		x[0] = '-';
	}
	while (c-- != 0 && x[c] != '-')
	{
		x[c] = (n % 10) + '0';
		n = n / 10;
	}
	return (x);
}
