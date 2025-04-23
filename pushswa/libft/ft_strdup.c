/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:55:14 by dmusomec          #+#    #+#             */
/*   Updated: 2024/12/08 19:52:04 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pipo;

	pipo = ft_calloc(ft_strlen(s) + 1, 1);
	if (!pipo)
		return (NULL);
	ft_strlcpy(pipo, s, ft_strlen(s) + 1);
	return (pipo);
}
