/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:32 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 21:14:30 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	sorted(t_stack **stack)
{
	t_stack	*supertemp;

	supertemp = *stack;
	while (supertemp && supertemp->next)
	{
		if (supertemp->content > supertemp->next->content)
			return (0);
		supertemp = supertemp->next;
	}
	return (1);
}
