/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:51:14 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/28 17:07:06 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap->target && *a != cheap)
		double_rotate(a, b);
	current_index(*a);
	current_index(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap->target && *a != cheap)
		double_reverse_rotate(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = get_cheapest(*a);
	if (c_node->above_median && c_node->target->above_median)
		rotate_both(a, b, c_node);
	else if (!(c_node->above_median) && !(c_node->target->above_median))
		reverse_rotate_both(a, b, c_node);
	prep_for_push(a, c_node, 'a');
	prep_for_push(b, c_node->target, 'b');
	push_to_stack(a, b, 'b');
}

static void	move_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	push_to_stack(b, a, 'a');
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !is_sort(*a))
		push_to_stack(a, b, 'b');
	if (len-- > 3 && !is_sort(*a))
		push_to_stack(a, b, 'b');
	while (len-- > 3 && !is_sort(*a))
	{
		init_a(*a, *b);
		move_to_b(a, b);
	}
	sort_for_3(a);
	while (*b)
	{
		init_b(*a, *b);
		move_to_a(a, b);
	}
	current_index(*a);
	min_top(a);
}
