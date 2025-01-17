/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:09:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/17 17:42:29 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker_isnum(char **arr)
{
	int	i;
	int	y;

	i = 0;
	while (arr[i])
	{
		y = 0;
		if (arr[i][y] == '-' || arr[i][y] == '+')
			y++;
		while (arr[i][y])
		{
			if (!ft_isdigit((int)(arr[i][y])))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

static int	checker_dup(t_stack *a, char **arr)
{
	long	ver;
	size_t	i;
	size_t	c;

	i = 0;
	a->var = malloc(sizeof(int) * a->size);
	if (!a->var)
		return (0);
	while (i < a->size)
	{
		ver = ft_atoi(arr[i]);
		if (ver > INT_MAX || ver < INT_MIN)
			return (0);
		a->var[i++] = (int)ver;
	}
	i = 0;
	while (i < a->size -1)
	{
		c = i + 1;
		while (c < a->size)
			if (a->var[i] == a->var[c++])
				return (0);
		i++;
	}
	return (1);
}

int	is_valid(t_stack *a, char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	a->size = i;
	if (!checker_isnum(argv))
		return (0);
	else if (!checker_dup(a, argv))
		return (0);
	return (1);
}
