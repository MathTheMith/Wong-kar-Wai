/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:49:46 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/11 14:37:35 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_from_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

static int	get_trimmed_len(char const *s, char const *set)
{
	int	i;
	int	len;
	int	trimmed_len;

	i = 0;
	len = ft_strlen(s);
	trimmed_len = len;
	while (s[i] && is_from_charset(s[i], set))
		i++;
	trimmed_len -= i;
	i = len - 1;
	while (trimmed_len > 0 && i >= 0 && is_from_charset(s[i], set))
	{
		i--;
		trimmed_len--;
	}
	return (trimmed_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	len = get_trimmed_len(s1, set);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (is_from_charset(s1[i], set))
		i++;
	while (j < len)
		new_str[j++] = s1[i++];
	new_str[j] = '\0';
	return (new_str);
}
