/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:20:48 by dmusomec          #+#    #+#             */
/*   Updated: 2025/03/27 15:21:55 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_realloc(void *ptr, size_t size)
{
    void    *new_ptr;

    if (!ptr)
        return (malloc(size));
    if (!size)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);
    ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}