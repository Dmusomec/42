/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:43 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/29 15:26:15 by dmusomec         ###   ########.fr       */
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

t_stack			*newlst(int content);
void			addtotop(t_stack **stack, t_stack *new);
t_stack			*lastnode(t_stack *head);
void			addbottom(t_stack **stack, t_stack *new);
unsigned int	sizeoflist(t_stack *head);
void			ft_free(char **str);
int				sorted(t_stack **stack);
void			freestack(t_stack **stack);
int				rotatebase(t_stack **stack);
int				pushbase(t_stack **receive, t_stack **send);
void			radix(t_stack **a, t_stack **b);
void			indexer(t_stack **stack);
void			startstack(t_stack **stack, char *av);

#endif