/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:01:04 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/21 21:12:49 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	isvalnum(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**parse(int ac, char **av)
{
	char	**args;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (!args || !*args)
		return (NULL);
	if (!isvalnum(args) || !checkmaxmin(args) || !checkdup(args))
		return (NULL);
	return (args);
}

int	*convert(char ** args, int size)
{
	int *nums;
	int	i;

	nums = malloc(sizeof(int) * size);
	if (!nums)
		return (NULL);
	i = 0;
	while (args[i])
	{
		nums[i] = ft_atoi(args[i]);
		i++;
	}
	return (nums);
}