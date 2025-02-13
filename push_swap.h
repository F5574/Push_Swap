/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:29:29 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/13 15:28:36 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

void 	sort_small(t_stack **a, int count);
void	sort_for_3(t_stack **a);
size_t	stack_len(t_stack **s);
void	double_swap_firsts(t_stack **a, t_stack **b);
void	double_rotate(t_stack **a, t_stack **b);
void	double_reverse_rotate(t_stack **a, t_stack **b);
void	swap_stack_firsts(t_stack **stack, char c, int flag);
void	push_to_stack(t_stack **input, t_stack **output, char c);
void	rotate_stack(t_stack **stack,  char c, int flag);
void	reverse_rotate_stack(t_stack **stack,  char c, int flag);
void	init_push_swap(t_stack **a, t_stack **b);
int		is_valid(t_stack **a, char **argv);
void	print_stack(t_stack *stack, const char *name);
void	free_stack(t_stack *stack);
int		main(int argc, char **argv);

#endif