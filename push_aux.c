/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:43 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/28 17:38:58 by gvon-ah-         ###   ########.fr       */
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

void	init_push_swap(t_stack **a, t_stack **b)
{
    print_stack(*a, "A");
    print_stack(*b, "B");
    ft_printf("pushing \n");

    // Test push_to_stack
    push_to_stack(a, b);
    push_to_stack(a, b);
    push_to_stack(a, b);
    push_to_stack(a, b);
    push_to_stack(a, b);

    ft_printf("after push_to_stack tests \n");
    print_stack(*a, "A");
    print_stack(*b, "B");

    // Test swap_stack_firsts
    swap_stack_firsts(a);
    swap_stack_firsts(b);

    ft_printf("after swap_stack_firsts tests \n");
    print_stack(*a, "A");
    print_stack(*b, "B");

    // Test rotate_stack
    rotate_stack(a);
    rotate_stack(a);
    rotate_stack(a);
    rotate_stack(a);
    rotate_stack(a);

    ft_printf("after rotate_stack tests \n");
    print_stack(*a, "A");
    print_stack(*b, "B");

    // Test inverse_rotate_stack
    inverse_rotate_stack(b);
    inverse_rotate_stack(b);
    inverse_rotate_stack(b);
    inverse_rotate_stack(b);
    inverse_rotate_stack(b);

    ft_printf("after inverse_rotate_stack tests \n");
    print_stack(*a, "A");
    print_stack(*b, "B");

   ft_printf("tests \n");
    rotate_stack(a);
	inverse_rotate_stack(b);
	print_stack(*a, "A");
    print_stack(*b, "B");
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
