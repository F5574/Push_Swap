/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:43 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/17 18:23:44 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	size_t i = 0;
	while (i < stack->size){
    printf("Stack %s: ", name);
    printf("%d ", stack->var[i]);
	printf(" size %zu", stack->size);
    printf("\n");
	i++;
	}
    printf("\n");

}

void	init_push_swap(t_stack *a, t_stack *b)
{
	b->var = malloc(sizeof(int) * a->size);
	if (!b->var)
		return ;
	b->size = 0;
	print_stack(a, "A");
	print_stack(b, "B");
	push_to_stack(a, b);
	push_to_stack(a, b);
	print_stack(a, "A");
	print_stack(b, "B");
}


void	free_stack(t_stack *stack)
{
	free(stack->var);
	stack->var = NULL;
}
