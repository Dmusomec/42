/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:24:33 by dmusomec          #+#    #+#             */
/*   Updated: 2025/01/24 19:50:04 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"
# include <stdio.h>

# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"
# define BASE10 "0123456789"

void	ft_putstr(char *str, size_t *counter);
void	ft_putbase(const char *str, unsigned long num, size_t *counter);
void	ft_hexpt(void *point, size_t *counter);
void	ft_putnbrfd(int n, int fd, size_t *counter);
void	ft_putchar(char c, size_t *counter);
int		ft_printf(const char *str, ...);

#endif