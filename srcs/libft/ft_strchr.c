/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:38:38 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 10:14:51 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((uint8_t)s[i] == (uint8_t)c)
			return ((char *)(&s[i]));
		i++;
	}
	if ((uint8_t)s[i] == (uint8_t)c)
		return ((char *)(&s[i]));
	return (NULL);
}
