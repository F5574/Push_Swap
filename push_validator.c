/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:09:00 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/03/05 16:12:47 by gvon-ah-         ###   ########.fr       */
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

static int	verify_overflow(char *arr)
{
	long	num;

	num = 0;
	num = ft_atoi(arr);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static int	init_stack(t_stack **a, char **argv, size_t i)
{
	t_stack	*new_node;
	t_stack	*current;

	while (argv[++i])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (0);
		if (!verify_overflow(argv[i]))
			return (free (new_node), 0);
		new_node->num = (int)ft_atoi(argv[i]);
		new_node->next = NULL;
		new_node->cheapest = false;
		if (*a == NULL)
			*a = new_node;
		else
		{
			current = *a;
			while (current->next)
				current = current->next;
			current->next = new_node;
		}
	}
	return (1);
}

static int	checker_dup(t_stack **a, char **arr)
{
	size_t	i;
	int		curr;
	int		flag;
	t_stack	*current;

	while (*a)
	{
		i = -1;
		while (arr[++i])
		{
			flag = 0;
			curr = (int)ft_atoi(arr[i]);
			current = *a;
			while (current)
			{
				if (current->num == curr && flag == 1)
					return (0);
				if (current->num == curr && flag == 0)
					flag = 1;
				current = current->next;
			}
		}
		a = &(*a)->next;
	}
	return (1);
}

int	is_valid(t_stack **a, char **argv)
{
	bool	ver;

	ver = true;
	if (checker_isnum(argv))
	{
		if (!init_stack(a, argv, -1))
		{
			free_stack(*a);
			ver = false;
		}
	}
	else
		ver = false;
	if (!checker_dup(a, argv))
		ver = false;
	if (!ver)
		ft_printf("Error \n");
	return (ver);
}
