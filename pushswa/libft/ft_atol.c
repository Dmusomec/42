/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:25:20 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 21:11:40 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = *(str++) == '-';
	while (*str >= '0' && *str <= '9')
	{
		if (sign && (result < (LONG_MIN + (*str - '0')) / 10))
			return (LONG_MIN);
		else if (!sign && (result > (LONG_MAX - (*str - '0')) / 10))
			return (LONG_MAX);
		result = result * 10 + (sign ? -(*str++ - '0') : *str++ - '0');
	}
	return (result);
}
