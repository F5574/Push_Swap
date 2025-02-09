/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortsmall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:13:47 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/04 21:31:44 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	sort_for_3(t_stack **a)
{
	t_stack	*current;

	current = *a;
	if (current->num > current->next->num && current->next->num < current->next->next->num && current->num < current->next->next->num)
	{
		swap_stack_firsts(a, 'a', 0);
	}
	else if (current->num > current->next->num && current->next->num > current->next->next->num)
	{
		swap_stack_firsts(a, 'a', 0);
		reverse_rotate_stack(a, 'a', 0);
	}
	else if (current->num > current->next->num && current->next->num < current->next->next->num)
	{
		rotate_stack(a, 'a', 0);
	}
	else if (current->num < current->next->num && current->next->num > current->next->next->num && current->num < current->next->next->num)
	{
		swap_stack_firsts(a, 'a', 0);
		rotate_stack(a, 'a', 0);
	}
	else if (current->num < current->next->num && current->next->num > current->next->next->num)
	{
		reverse_rotate_stack(a, 'a', 0);
	}
}

void	sort_small(t_stack **a, int count)
{
    t_stack	*current;
	
	if (count == 2)
	{
		current = *a;
		if (current->num > current->next->num)
			swap_stack_firsts(a,'a',0 );
	}
	if (count == 3)
		sort_for_3(a);
}
