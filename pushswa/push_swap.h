/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:43 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/23 21:16:45 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

t_stack	*newlst(int content);
void	addtotop(t_stack **stack, t_stack *new);
t_stack	*lastnode(t_stack *head);
void	addbottom(t_stack **stack, t_stack *new);
unsigned int	sizeoflist(t_stack *head);
void	ft_free(char **str);
int	sorted(t_stack **stack);
void	freestack(t_stack **stack);

#endif