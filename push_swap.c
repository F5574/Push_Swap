/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:48 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/24 15:39:45 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		if (!argv[1])
			return (free(argv[0]), free(argv), 1);	
	}
	else
	 	argv = &argv[1];
	if (is_valid(&a, argv))
		init_push_swap(&a, &b);
	else
		ft_printf("Error \n");
	
	return (0);
}
