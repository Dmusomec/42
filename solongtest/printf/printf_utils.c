/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_Utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:18:32 by dmusomec          #+#    #+#             */
/*   Updated: 2025/01/24 17:38:13 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, size_t *counter)
{
	if (!str)
		*counter += write(1, "(null)", 6);
	else
	{
		while (*str)
		{
			ft_putchar(*str, counter);
			str++;
		}
	}
}

void	ft_putbase(const char *str, unsigned long num, size_t *counter)
{
	unsigned int	len;

	len = ft_strlen(str);
	if (num >= len)
		ft_putbase(str, num / len, counter);
	*counter += write(1, &str[num % len], 1);
}

void	ft_hexpt(void *point, size_t *counter)
{
	unsigned long	pt;

	if (point == 0)
		*counter += write(1, "(nil)", 5);
	else
	{
		pt = (unsigned long)point;
		*counter += write(1, "0x", 2);
		ft_putbase("0123456789abcdef", pt, counter);
	}
}

void	ft_putnbrfd(int n, int fd, size_t *counter)
{
	char	c;

	if (n == -2147483648)
	{
		*counter += write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*counter += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbrfd((n / 10), fd, counter);
	}
	c = (n % 10) + '0';
	*counter += write(fd, &c, 1);
}
