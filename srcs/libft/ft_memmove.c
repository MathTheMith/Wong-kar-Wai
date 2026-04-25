/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:26:24 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 10:19:05 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		i = 0;
		while (i < (int)n)
		{
			((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
			i++;
		}
		return (dest);
	}
	i = n - 1;
	while (i >= 0)
	{
		((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
		i--;
	}
	return (dest);
}
