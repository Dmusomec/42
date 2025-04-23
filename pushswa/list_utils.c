/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:26 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 20:12:15 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newlst(int content)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
}

void	addtotop(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*lastnode(t_stack *head)
{
	t_stack *supertemp;

	supertemp = head;
	while (supertemp->next)
		supertemp = supertemp->next;
	return (supertemp);
}

void	addbottom(t_stack **stack, t_stack *new)
{
	t_stack	*huh;

	if (*stack)
	{
		huh = lastnode(*stack);
		huh->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

unsigned int	sizeoflist(t_stack *head)
{
	unsigned int	i;
	t_stack	*supertemp;

	i = 0;
	supertemp = head;
	while (supertemp)
	{
		supertemp = supertemp->next;
		i++;
	}
	return (i);
}
