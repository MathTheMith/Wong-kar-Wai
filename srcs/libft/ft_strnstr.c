/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:02:47 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 10:16:14 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j <= len)
		{
			if (!big[i + j] && little[j])
				break ;
			if (!little[j])
				return ((char *)&big[i]);
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		i++;
	}
	return (NULL);
}
