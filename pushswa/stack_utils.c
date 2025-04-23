/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:52:20 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 21:16:37 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *getmin(t_stack **stack)
{
	t_stack	*supertemp;
	t_stack *min;
	int	f;

	supertemp = *stack;
	min = NULL;
	f = 0;
	if (supertemp)
	{
		while (supertemp)
		{
			if ((supertemp->index == -1) && (!f || supertemp->content < min->content))
			{
				min = supertemp;
				f = 1;
			}
			supertemp = supertemp->next;
		}
	}
	return (min);
}

void	indexer(t_stack **stack)
{
	t_stack *supertemp;
	int	index;

	index = 0;
	supertemp = getmin(stack);
	while (supertemp)
	{
		supertemp->index = index++;
		supertemp = getmin(stack);
	}
}

void	freestack(t_stack **stack)
{
	t_stack	*supertemp;
	t_stack	*tmp;

	supertemp = *stack;
	while (supertemp)
	{
		tmp = supertemp;
		supertemp = supertemp->next;
		free(tmp);
	}
	free(stack);
}
