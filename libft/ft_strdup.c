/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:37:32 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/02/24 15:58:16 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	size_t	i;
	char	*dst;

	l = ft_strlen(s1);
	i = -1;
	dst = ft_calloc(sizeof(char), (l + 1));
	if (!dst)
		return (NULL);
	while (++i < l)
		dst[i] = s1[i];
	return (dst);
}
