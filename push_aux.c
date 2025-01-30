/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:43 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/30 16:11:25 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
     printf("Stack %s: ", name);
    while (stack)
    {
        printf("%d ", stack->num);
        stack = stack->next;
    }
    printf("\n");
}

void double_swap_firsts(t_stack **a, t_stack **b)
{
	swap_stack_firsts(a, ' ',1);
	swap_stack_firsts(b, ' ', 1);
	ft_printf("ss\n");
}

void double_rotate(t_stack **a, t_stack **b)
{
	rotate_stack(a, ' ',1);
	rotate_stack(b, ' ', 1);
	ft_printf("rr\n");
}

void double_reverse_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a, ' ',1);
	reverse_rotate_stack(b, ' ', 1);
	ft_printf("rrr\n");
}

void	init_push_swap(t_stack **a, t_stack **b)
{
    print_stack(*a, "A");
    print_stack(*b, "B");
    ft_printf("pushing \n");

	push_to_stack(a,b, 'b');
	push_to_stack(a,b, 'b');
	push_to_stack(a,b, 'b');
	push_to_stack(a,b, 'b');
	
	print_stack(*a, "A");
    print_stack(*b, "B");
	
    ft_printf("sort \n");
	double_reverse_rotate(a,b);
	print_stack(*a, "A");
    print_stack(*b, "B");
}