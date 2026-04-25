/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:29:57 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/11 14:37:04 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_sub_str_len(char const *s, size_t max_len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < max_len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	sub_str_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		sub_str_len = 0;
	else
		sub_str_len = get_sub_str_len(&s[start], len);
	new_str = malloc(sizeof(char) * (sub_str_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < sub_str_len)
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
