/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:26:28 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/20 20:06:06 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkdup(char **mat)
{
	int	i;
	int	supertemp;
	int j;

	i = 0;
	supertemp = 0;
	j = 0;
	while (mat[i])
	{
		supertemp = ft_atoi(mat[i]);
		j = i + 1;
		while (mat[j])
		{
			if (ft_atoi(mat[j]) == supertemp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkmaxmin(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		if (ft_atol(mat[i]) > INT_MAX || ft_atol(mat[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	isvalnum(char **mat)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (mat[i])
	{
		c = 0;
		if (mat[i][c] == '-' || mat[i][c] == '+')
			c++;
		while (mat[i][c] != '\0' && mat[i][c] >= '0' && mat[i][c] <= '9')
			c++;
		if (mat[i][c] != '\0')
			return (0);
		i++;
	}
	return (1);
}

char	**prendi(char *str)
{
	char	**mat;

	mat = ft_split(str, ' ');
	if (!mat)
		return (NULL);
	if (!isvalnum(mat))
		return (NULL);
	if (!checkmaxmin(mat))
		return (NULL);
	if (!checkdup)
		return (NULL);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		prendi(av[1]);
	}
}
