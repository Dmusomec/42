/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:26:28 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/22 09:03:57 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack **a, int *indexes, int size)
{
	while (size--)
		ft_lstadd_back(a, ft_lstnew(indexes[size]));
}

int	main(int ac, char **av)
{
	char	**args;
	int		*nums;
	int		*indexes;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	args = parse(ac, av);
	if (!args)
		return (ft_putstr_fd("Error\n", 2), 1);
	nums = convert(args, args_size(args));
	indexes = normalize(nums, args_size(args));
	init_stack(&a, indexes, args_size(args));
	free(nums);
	free(indexes);
	if (!is_sorted(a))
		radix(&a, &b, args_size(args));
	free_stack(&a);
	free_mat(args);
	return (0);
}
