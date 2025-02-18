/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:51:14 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/18 17:45:07 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h";

static void rotate_both(t_stack **b, t_stack **a, t_stack *cheap, bool rr)
{
	while (*b != cheap->target && *a != cheap)
	{
		if (rr)
			double_reverse_rotate(a,b);
		else
			double_rotate(a,b);
	}
	current_index(*a);
	current_index(*b);
}

static void move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = get_cheapest(*a);
	if (c_node->above_median && c_node->target->above_median)
		rotate_both(a, b, c_node, 0);
	else if (!(c_node->above_median) && !(c_node->target->above_median))
		rotate_both(a, b, c_node, 1);
	prep_for_push(a, c_node, 'a');
	prep_for_push(b, c_node, 'b');
	push_to_stack(a,b, 'b');
}

static void move_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	push_to_stack(b,a, 'a');
}

static void min_top(t_stack **stack)
{
	while((*stack)->num != min_n(*stack)->num)
	{
		if (min_n(*a)->above_median)
			rotate_stack(stack, 'a' ,0);
		else
			reverse_rotate_stack(stack, 'a', 0);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int len;

	len = stack_len(a);
	if (len-- > 3 && !sorted(*a))
		push_to_stack(a, b, 'b');
	if (len-- > 3 && !sorted(*a))
		push_to_stack(a, b, 'b');
	while (len-- > 3 && !sorted(*a))
	{
		init_a(*a, *b);
		move_to_b(a,b);
	}
	sort_for_3(a);
	while (*b)
	{
		init_b(*a, *b);
		move_to_a(a,b);
	}
	current_index(*a);
	min_top(a);
}