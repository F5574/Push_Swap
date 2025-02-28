/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:55:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/28 16:32:39 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_median)
				rotate_stack(stack, 'a', 0);
			else
				reverse_rotate_stack(stack, 'a', 0);
		}
		else if (c == 'b')
		{
			if (top->above_median)
				rotate_stack(stack, 'b', 0);
			else
				reverse_rotate_stack(stack, 'b', 0);
		}
	}
}

void	min_top(t_stack **stack)
{
	while ((*stack)->num != min_n(*stack)->num)
	{
		if (min_n(*stack)->above_median)
			rotate_stack(stack, 'a', 0);
		else
			reverse_rotate_stack(stack, 'a', 0);
	}
}
