/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_adds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:51:55 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/28 17:07:32 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	add_front(t_stack **stack, t_stack *new)
// {
// 	new->next = *stack;
// 	*stack = new;
// }

// void	add_back(t_stack **stack, t_stack *new)
// {
// 	t_stack	*cur;

// 	if (!*stack)
// 	{
// 		*stack = new;
// 		return ;
// 	}
// 	cur = *stack;
// 	while (cur->next)
// 		cur = cur->next;
// 	cur->next = new;
// }