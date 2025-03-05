/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:02:47 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/03/05 17:02:22 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	res;
	long	ver;
	int		a;
	int		count;

	a = 0;
	res = 0;
	count = 1;
	ver = 2147483648;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
		if (str[a++] == '-')
			count = count * -1;
	while (str[a] >= '0' && str[a] <= '9')
	{
		res = res * 10 + (str[a++] - '0');
		if (res > ver)
			return (ver);
	}
	return (count * res);
}
