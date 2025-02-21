/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_init_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:45:11 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/21 16:02:38 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*curr;
	t_stack	*target;
	long		best;

	while (b)
	{
		best = LONG_MAX;
		curr = a;
		while (curr)
		{
			if (curr->num > b->num && curr->num < best)
			{
				best = curr->num;
				target = curr;
			}
			curr = curr->next;
		}
		if (best == LONG_MAX)
			b->target = min_n(a);
		else
			b->target = target;
		b = b->next;
	}
}


void	init_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a,b);
}