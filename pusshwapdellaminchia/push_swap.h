/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:26:16 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/21 21:35:22 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct	s_stack
{
	int	content;
	struct s_stack	*next;
}	t_stack;

char	**parse(int ac, char **av);
int		validate(char **args);
int		*convert(char **args, int size);
int		*norm(int *nums, int size);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
int		sorted(t_stack *stack);
void	free_stack(t_stack *stack);
void	radix(t_stack **a, t_stack **b, int	size);
void	free_mat(char **mat);
int		args_size(char **args);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);

#endif