/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:17 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/24 18:17:57 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pa(t_stack **a, t_stack **b)
{
    if (pushbase(a, b) == -1)
        return (-1);
    ft_printf("pa\n");
    return (0);
}

int pb(t_stack **a, t_stack **b)
{
    if (pushbase(b, a) == -1)
        return (-1);
    ft_printf("pb\n");
    return (0);
}

int ra(t_stack **a)
{
    if (rotatebase(a) == -1)
        return (-1);
    ft_printf("ra\n");
    return (0);
}

int getmax(t_stack **stack)
{
    t_stack *hed;
    int maxval;
    int maxbits;

    hed = *stack;
    maxval = hed->index;
    maxbits = 0;
    while (hed)
    {
        if (hed->index > maxval)
            maxval = hed->index;
        hed = hed->next;
    }
    while ((maxval >> maxbits) != 0)
        maxbits++;
    return (maxbits);
}

void    radix(t_stack **a, t_stack **b)
{
    t_stack *a_hed;
    int i;
    int c;
    int maxbits;
    int size;

    i = 0;
    a_hed = *a;
    maxbits = getmax(a);
    while (i < maxbits)
    {
		size = sizeoflist(a_hed);
        c = 0;
        while (c++ < size)
		{
			a_hed = *a;
			if (((a_hed->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (sizeoflist(*b) != 0)
			pa(a, b);
		i++;
    }
}
