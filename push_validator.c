/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:09:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/13 17:16:09 by gvon-ah-         ###   ########.fr       */
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
	size_t		i;
	size_t		c;

	i = 0;
	ver = 2147483648;
	a->var = malloc(sizeof(long) * (a->size + 1));
	if (!a->var)
		return (0);
	while (i < a->size)
	{
		a->var[i] = ft_atoi(arr[i]);
		if (a->var[i++] == ver)
			return (free(a->var), 0);
	}
	i = 0;
	while (arr[i++])
	{
		c = i + 1;
		while (c < a->size)
			if (a->var[i] == a->var[c++])
				return (free(a->var), 0);
	}
	return (free(a->var), 1);
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
