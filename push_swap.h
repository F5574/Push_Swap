/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:29:29 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/19 17:30:05 by gvon-ah-         ###   ########.fr       */
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

//push_aux.c


void	print_stack(t_stack *stack, const char *name); // remove later
void	double_swap_firsts(t_stack **a, t_stack **b);
void	double_rotate(t_stack **a, t_stack **b);
void	double_reverse_rotate(t_stack **a, t_stack **b);
void	init_push_swap(t_stack **a, t_stack **b);

//push_functions.c

void	swap_stack_firsts(t_stack **stack, char c, int flag);
void	push_to_stack(t_stack **input, t_stack **output, char c);
void	rotate_stack(t_stack **stack,  char c, int flag);
void	reverse_rotate_stack(t_stack **stack,  char c, int flag);
void	free_stack(t_stack *stack);

//push_init_a.c

void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	init_a(t_stack *a, t_stack *b);

//push_init_b.c

void	init_b(t_stack *a, t_stack *b);

//push_moves.c

void	sort_stacks(t_stack **a, t_stack **b);

//push_prep.c

void	prep_for_push(t_stack **stack, t_stack *top, char c);

//push_sortsmall.c

void 	sort_small(t_stack **a, int count);
void	sort_for_3(t_stack **a);
size_t	stack_len(t_stack *s);

//push_validator.c

int	is_valid(t_stack **a, char **argv);

// push_utils.c

t_stack	*last_n(t_stack *stack);
bool	is_sort(t_stack *stack);
t_stack	*min_n(t_stack *stack);
t_stack	*max_n(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);

//push_swap.c

int		main(int argc, char **argv);
#endif