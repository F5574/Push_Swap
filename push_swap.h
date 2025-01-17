/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:29:29 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/17 17:42:00 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_stack
{
	int			*var;
	size_t		size;
}	t_stack;

void	swap_stack_firsts(t_stack *stack);
void	push_to_stack(t_stack *input, t_stack *output);
void	Swap_Stacks(t_stack *stack);
void	init_push_swap(t_stack *a, t_stack *b);
int		is_valid(t_stack *a, char **argv);
int		main(int argc, char **argv);

#endif