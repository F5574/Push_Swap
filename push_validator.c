/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:09:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/10 21:28:17 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char **argv)
{
	if (!checker_isnum(argv))
		return (0);
	else if (!checker_dup(argv))
		return (0);
	return (1);
}

int	checker_isnum(char **arr)
{
	int	i;
	int	y;

	i = 0;
	while (arr[i])
	{
		y = 0;
		while (arr[i][y])
		{
			if (y == 0)
				if (!(arr[i][y] == '-' || arr[i][y] == '+'))
					if (!ft_isdigit((int)(arr[i][y])))
						return (0);
			if (!ft_isdigit((int)(arr[i][y])))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	checker_dup(char **arr)
{
	
}

