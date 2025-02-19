/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:43 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/19 18:57:09 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
    ft_printf("Stack %s: ", name);
    while (stack)
    {
               ft_printf("num: %d, index: %d, cost: %d, above_median: %d, cheapest: %d, target: %p\n",
                  stack->num, stack->index, stack->cost, stack->above_median, stack->cheapest, (void*)stack->target);
    }
    ft_printf("\n");
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
	int		count;
	t_stack	*for_count;

	count = 0;
	for_count = *a;
	while(for_count->next)
	{
		for_count = for_count->next;
		count++;
	}
	//ft_printf("count inital stack %d \n", count + 1);
	
	if(count < 3)
		sort_small(a, count + 1);
	else
	{
	ft_printf("sort_big \n");
		sort_stacks(a,b);
    print_stack(*a, "A");
    print_stack(*b, "B");
	ft_printf("count: %i", (int)stack_len(*a));
	}
}