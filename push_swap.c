/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:48 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/03/05 16:17:55 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split = ft_split(argv[1], 32);
		if (!split || !argv[1])
			return (free(split), 1);
		argv = split;
	}
	else
		argv = &argv[1];
	if (is_valid(&a, argv))
		init_push_swap(&a, &b);
	if (split)
		free_arg(split);
	free_stack(a);
	return (0);
}
// for test: ./push_swap $(shuf -i 1-500 -n 500) | wc -w
