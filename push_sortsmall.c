/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortsmall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:13:47 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/28 17:06:55 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	aux_sort_for_3(t_stack **a)
{
	swap_stack_firsts(a, 'a', 0);
	reverse_rotate_stack(a, 'a', 0);
}

void	sort_for_3(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	if (curr->num > curr->next->num
		&& curr->next->num < curr->next->next->num
		&& curr->num < curr->next->next->num)
		swap_stack_firsts(a, 'a', 0);
	else if (curr->num > curr->next->num
		&& curr->next->num > curr->next->next->num)
		aux_sort_for_3(a);
	else if (curr->num > curr->next->num
		&& curr->next->num < curr->next->next->num)
		rotate_stack(a, 'a', 0);
	else if (curr->num < curr->next->num
		&& curr->next->num > curr->next->next->num
		&& curr->num < curr->next->next->num)
	{
		swap_stack_firsts(a, 'a', 0);
		rotate_stack(a, 'a', 0);
	}
	else if (curr->num < curr->next->num
		&& curr->next->num > curr->next->next->num)
		reverse_rotate_stack(a, 'a', 0);
}

void	sort_small(t_stack **a, int count)
{
	t_stack	*current;

	if (count == 2)
	{
		current = *a;
		if (current->num > current->next->num)
			swap_stack_firsts(a, 'a', 0);
	}
	if (count == 3)
		sort_for_3(a);
}

size_t	stack_len(t_stack *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}
