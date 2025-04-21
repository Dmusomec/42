/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:18:04 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/21 21:38:17 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack *supertmp;

	if (!*a || !(*a)->next)
		return ;
	supertmp = *a;
	*a = (*a)->next;
	supertmp->next = NULL;
	ft_lstlast(*a)->next = supertmp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*supertemp;

	if (!*a)
		return ;
	supertemp = *a;
	*a = (*a)->next;
	supertemp->next = *b;
	*b = supertemp;
}

void	pa(t_stack **a, t_stack **b)
{
	pb (b, a);
}

int	sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack *supertemp;

	while (*stack)
	{
		supertemp = (*stack)->next;
		free(*stack);
		*stack = supertemp;
	}
}
