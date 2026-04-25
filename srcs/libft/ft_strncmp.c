/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:33:12 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 10:16:10 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if ((uint8_t)s1[i] != (uint8_t)s2[i])
			return ((uint8_t)s1[i] - (uint8_t)s2[i]);
		i++;
	}
	if (i < n)
		return ((uint8_t)s1[i] - (uint8_t)s2[i]);
	return (0);
}
