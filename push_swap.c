/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:48 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/13 17:14:04 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack a;
	t_stack	b;

	a = (t_stack){.var = NULL, .size = 0};
	b = (t_stack){.var = NULL, .size = 0};
	i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], 32);
	else
		argv = &argv[1];
	if (is_valid(&a, argv))
		init_push_swap();
	ft_printf("fez alguma coisa");
	return (0);
}


