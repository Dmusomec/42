/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:32 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:21 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
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

void	startstack(t_stack **stack, char *av)
{
	t_stack	*new;
	char	**mat;
	int		i;

	i = 0;
	mat = ft_split(av, ' ');
	if (!mat)
		return ;
	while (mat[i])
	{
		new = newlst(ft_atoi(mat[i]));
		addbottom(stack, new);
		i++;
	}
	indexer(stack);
	ft_free(mat);
}
