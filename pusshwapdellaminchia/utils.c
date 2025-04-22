/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:25:27 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/22 09:01:59 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mat(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

int	args_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	*normalize(int *nums, int size)
{
	int	*sorted;
	int	*indexes;
	int	i;
	int	j;

	sorted = malloc(sizeof(int) * size);
	ft_memcpy(sorted, nums, sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
			if (sorted[j] > sorted[j + 1])
				ft_swap(&sorted[j], &sorted[j + 1]);
	}
	indexes = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (nums[i] == sorted[j])
				indexes[i] = j;
	}
	free(sorted);
	return (indexes);
}
