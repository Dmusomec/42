/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:52:20 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/29 13:37:05 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*getmin(t_stack **stack)
{
	t_stack	*supertemp;
	t_stack	*min;
	int		f;

	supertemp = *stack;
	min = NULL;
	f = 0;
	if (supertemp)
	{
		while (supertemp)
		{
			if ((supertemp->index == -1) && (!f
					|| supertemp->content < min->content))
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
	t_stack	*supertemp;
	int		index;

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

int	rotatebase(t_stack **stack)
{
	t_stack	*hed;
	t_stack	*teil;

	if (sizeoflist(*stack) < 2)
		return (-1);
	hed = *stack;
	teil = lastnode(hed);
	*stack = hed->next;
	hed->next = NULL;
	teil->next = hed;
	return (0);
}

int	pushbase(t_stack **receive, t_stack **send)
{
	t_stack	*supertemp;
	t_stack	*receive_h;
	t_stack	*send_h;

	if (sizeoflist(*send) == 0)
		return (-1);
	receive_h = *receive;
	send_h = *send;
	supertemp = send_h;
	send_h = send_h->next;
	*send = send_h;
	if (!receive_h)
	{
		receive_h = supertemp;
		receive_h->next = NULL;
		*receive = receive_h;
	}
	else
	{
		supertemp->next = receive_h;
		*receive = supertemp;
	}
	return (0);
}
