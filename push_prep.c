/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:55:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/19 18:32:49 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
