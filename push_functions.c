/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:45 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:37 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_firsts(t_stack **stack, char c, int flag)
{
	int	buff;

	if (*stack && (*stack)->next)
	{
		buff = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = buff;
	}
	if (!flag)
		ft_printf("s%c\n", c);
}

void	push_to_stack(t_stack **input, t_stack **output, char c)
{
	t_stack *temp;
	
	if(*input)
	{
		temp = *input;
		*input = (*input)->next;
		temp->next = *output;
		*output = temp;
	}
	ft_printf("p%c\n", c);
}

void	rotate_stack(t_stack **stack, char c, int flag)
{
	t_stack *first;
	t_stack *last;

	if(*stack && (*stack)->next)
	{
		first = *stack;
		*stack = first->next;
		first->next = NULL;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	if (!flag)
		ft_printf("r%c\n", c);
}

void	reverse_rotate_stack(t_stack **stack, char c, int flag)
{
	t_stack *before;
	t_stack *curr;

	if (*stack && (*stack)->next)
	{
		curr = *stack;
		while (curr->next)
		{
			before = curr;
			curr = curr->next;	
		}
		before->next = NULL;
		curr->next = *stack;
		*stack = curr;
	}
	if (!flag)
		ft_printf("rr%c\n", c);
}

void	free_stack(t_stack *stack)
{
 	t_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
