/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:21:29 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/17 08:26:00 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, size_t *counter)
{
	*counter += write(1, &c, 1);
}

static void	type(const char *str, va_list args, size_t *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), counter);
	if (*str == 's')
		ft_putstr(va_arg(args, char *), counter);
	if (*str == 'p')
		ft_hexpt(va_arg(args, void *), counter);
	if (*str == 'i' || *str == 'd')
		ft_putnbrfd(va_arg(args, int), 1, counter);
	if (*str == 'u')
		ft_putbase(BASE10, va_arg(args, unsigned int), counter);
	if (*str == 'x')
		ft_putbase(BASE16, va_arg(args, unsigned int), counter);
	if (*str == 'X')
		ft_putbase(BASE16UPPER, va_arg(args, unsigned int), counter);
	if (*str == '%')
		ft_putchar('%', counter);
}

static void	runbi(const char *str, va_list args, size_t *counter)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			type(str, args, counter);
			str++;
		}
		else
		{
			ft_putchar(*str, counter);
			str++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	counter;

	counter = 0;
	va_start(args, str);
	runbi(str, args, &counter);
	va_end(args);
	return (counter);
}

int	main()
{
	int a = 0;
    int printed_chars;

    printed_chars = ft_printf("Character: %c\n", 'p');
    printf("Printed characters: %d\n", printed_chars);

    printed_chars = ft_printf("String: %s\n", "Hello, World!");
    printf("Printed characters: %d\n", printed_chars);

    printed_chars = ft_printf("Pointer: %p %p\n", 0, 0);
	printf("Pointer: %p %p\n", 0, 0);
    printf("Printed characters: %d\n", printed_chars);

    printed_chars = ft_printf("Integer: %i\n", 12345);
    printf("Printed characters: %d\n", printed_chars);

	printed_chars = ft_printf("Unsigned: %u\n", 12345U);
    printf("Printed characters: %d\n", printed_chars);

	printed_chars = ft_printf("Hex (lowercase): %x\n", 1234567U);
    printf("Printed characters: %d\n", printed_chars);

    printed_chars = ft_printf("Hex (uppercase): %X\n", 1234567U);
    printf("Printed characters: %d\n", printed_chars);

    printed_chars = ft_printf("Percentage: %%\n");
    printf("Printed characters: %%%%%d\n", printed_chars);
	ft_printf("Printed characters: %%%%%d\n", printed_chars);
	printf("Printed characters: %%%%d\n", printed_chars);
	ft_printf("Printed characters: %%%%d\n", printed_chars);

    return 0;
}