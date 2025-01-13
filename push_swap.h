/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:29:29 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/13 17:10:59 by gvon-ah-         ###   ########.fr       */
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
	long	*var;
	size_t	size;
}	t_stack;

int	is_valid(t_stack *a, char **argv);
int		main(int argc, char **argv);
void	init_push_swap(void);

#endif