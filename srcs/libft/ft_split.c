/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:01:28 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/11 14:37:49 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s1, char c)
{
	int		i;
	int		count;
	bool	flag;

	i = 0;
	count = 0;
	flag = true;
	while (s1[i])
	{
		if (s1[i] == c)
			flag = true;
		else if (flag)
		{
			count++;
			flag = false;
		}
		i++;
	}
	return (count);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	create_word(char const *s1, char c, char **split, int *j)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s1[len] && s1[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	split[(*j)++] = word;
	if (!word)
	{
		free_split(split);
		return (ERR_INT);
	}
	i = 0;
	while (i < len)
	{
		word[i] = s1[i];
		i++;
	}
	word[i] = '\0';
	return (0);
}

static char	**create_split(char const *s1, char c, char **split)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	j = 0;
	flag = true;
	while (s1[i])
	{
		if (s1[i] == c)
			flag = true;
		else if (flag)
		{
			if (create_word(&s1[i], c, split, &j) == ERR_INT)
				return (NULL);
			flag = false;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s1, char c)
{
	char	**split;

	if (!s1)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(s1, c) + 1));
	if (!split)
		return (NULL);
	return (create_split(s1, c, split));
}
