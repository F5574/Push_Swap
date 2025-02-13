/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:37:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/13 15:55:43 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_n(t_stack *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	is_sort(t_stack *stack)
{
	if(!stack)
		return (true);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*min_n(t_stack *stack)
{
	int	min;
	t_stack	*min_n;
	
	if(!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_n = stack;
		}
		stack = stack->next;
	}
	return (min_n);
}

t_stack	*max_n(t_stack *stack)
{
	int	max;
	t_stack	*max_n;
	
	if(!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->num < max)
		{
			max = stack->num;
			max_n = stack;
		}
		stack = stack->next;
	}
	return (max_n);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if(!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}