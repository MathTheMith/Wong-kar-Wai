/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:45:55 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 10:15:55 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;
	size_t	k;

	k = ft_strlen(src);
	i = 0;
	j = 0;
	if (size == 0)
		return (k);
	ret = k;
	k = 0;
	while (dst[k] && k < size)
		k++;
	if (k == size)
		return (ret + size);
	while (dst[i])
		i++;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (k + ret);
}
