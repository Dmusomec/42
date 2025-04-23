/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:13:08 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 05:16:58 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	process_bit(t_stack **src, t_stack **dest, int bit, int size)
{
	int	j;

	j = 0;
	while (j++ < size)
	{
		if (((*src)->content >> bit) & 1)
			ra(src);    // Keep in src stack if bit is 1
		else
			pb(src, dest);  // Push to dest if bit is 0
	}
}

void	radix(t_stack **a, t_stack **b, int size)
{
	int		max_bits;
	int		bit;
	t_stack	**src;
	t_stack	**dest;

	max_bits = get_max_bits(size);
	bit = -1;
	src = a;
	dest = b;
	while (++bit < max_bits)
	{
		process_bit(src, dest, bit, size);
		// Switch src/dest for next bit (no need to move back)
		if (bit < max_bits - 1)
		{
			t_stack	**temp = src;
			src = dest;
			dest = temp;
		}
	}
	// Ensure all elements end up in A
	while (*b)
		pa(a, b);
}