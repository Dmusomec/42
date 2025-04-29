/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:01 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:55 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdup(char **args)
{
	int	i;
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

int	huh(char **mat)
{
	if (!checkmaxmin(mat))
	{
		ft_free(mat);
		return (0);
	}
	if (!checkdup(mat))
	{
		ft_free(mat);
		return (0);
	}
	ft_free(mat);
	return (1);
}

int	validateargs(char *arg)
{
	int		i;
	char	**mat;

	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if (!arg[i])
			break ;
		if (arg[i] == '-' || arg[i] == '+')
		{
			if (i > 0 && arg[i - 1] != ' ')
				return (0);
			i++;
		}
		if (!ft_isdigit(arg[i]))
			return (0);
		while (ft_isdigit(arg[i]))
			i++;
	}
	mat = ft_split(arg, ' ');
	if (!huh(mat))
		return (0);
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
		a = (t_stack **)malloc(sizeof(t_stack *));
		b = (t_stack **)malloc(sizeof(t_stack *));
		if (!a || !b)
			return (0);
		*a = NULL;
		*b = NULL;
		startstack(a, av[1]);
		if (sorted(a))
		{
			freestack(a);
			freestack(b);
			return (0);
		}
		radix(a, b);
		freestack(a);
		freestack(b);
	}
	return (0);
}
