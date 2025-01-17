/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:45 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/17 18:20:22 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_firsts(t_stack *stack)
{
	int	buff;

	if (stack->size > 1)
	{
		buff = stack->var[0];
		stack->var[0] = stack->var[1];
		stack->var[1] = buff;
	}
}

void	push_to_stack(t_stack *input, t_stack *output)
{
	int		buff;
	size_t	i;

	if (input->size > 0)
	{
		buff = input->var[0];
		i = output->size;
		while (i > 0)
		{
			output->var[i] = output->var[i - 1];
			i--;
		}
		output->var[0] = buff;
		output->size++;
		i = 0;
		while (i < input->size -1)
		{
			input->var[i] = input->var[i + 1];
			i++;
		}
		input->var[input->size -1] = 0;
		input->size--;
	}
}

