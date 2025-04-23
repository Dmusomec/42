/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:01 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 21:17:15 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	startstack(t_stack **stack, char **av)
{
	t_stack	*new;
	char	**mat;
	int	i;

	i = 0;
	mat = ft_split(av[1], ' ');
	while (mat[i])
	{
		new = newlst(ft_atoi(mat[i]));
		addbottom(stack, new);
		i++;
	}
	indexer(stack);
	ft_free(mat);
}

int checkdup(char **args)
{
    int i;
    int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	checkmaxmin(char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	validateargs(char *arg)
{
	long	suptemp;
	int	i;
	char **mat;

	i = 0;
	while (arg[i] != '\0')
	{
		if ((arg[i] == '-' || arg[i] == '+') 
		&& (arg[i + 1] != '-' || arg[i + 1] != '+'))
			return (0);
		while (arg[i] == ' ' || arg[i] == '-' || arg[i] == '+')
			i++;
		while (ft_isdigit(arg[i]))
			i++;
		return (0);
	}
	mat = ft_split(arg, ' ');
	if (!checkmaxmin(mat))
		return (0);
	if (!checkdup(mat))
		return (0);
	ft_free(mat);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	if (ac == 2)
	{
		if (!validateargs(av[1]))
			return (0);
		a = (t_stack **)malloc(sizeof(t_stack));
		b = (t_stack **)malloc(sizeof(t_stack));
		*a = NULL;
		*b = NULL;
		startstack(a, av[1]);
		if (sorted(a))
		{
			freestack(a);
			freestack(b);
			return (0);
		}
		
	}
}
