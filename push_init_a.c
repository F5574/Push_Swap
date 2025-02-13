/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_init_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:46:32 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/13 18:46:09 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	current_index(t_stack *stack)
{
	int 	i;
	int 	median;

	i = 0;
	if(!stack)
		return ;
	median = stack_len(stack) / 2;
	while(stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack	*target;
	long	best;
	
	while (a)
	{
		best = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > best)
			{
				best = current_b->num;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}	
}

static void	cost_analysis_a(t_stack  *a, t_stack *b)
{
	int b_len;
	int a_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = a_len - (a->index);
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += b_len - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	c_value;
	t_stack	*c_node;

	if (!stack)
		return ;
	c_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < c_value)
		{
			c_value = stack->cost;
			c_node = stack;
		}
		stack = stack->next;
	}
	c_node->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a,b);
	cost_analysis_a(a,b);
	set_cheapest(a);
}
