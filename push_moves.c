/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortbig_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:51:14 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/13 15:30:38 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h";

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
static void move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = get_cheapest(*a);
	if (c_node->above_median && c_node->target->above_median)
		double_rotate(a, b);
	else if (!(c_node->above_median) && !(c_node->target->above_median))
		double_reverse_rotate(a, b);
	
}