/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:22:11 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 09:59:50 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

static void	get_sign(const char *nptr, int *i, int *sign)
{
	if (nptr[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (nptr[*i] == '+')
	{
		*sign = 1;
		(*i)++;
	}
	else
		*sign = 1;
}

int	ft_atoi(const char *nptr)
{
	uint64_t	return_value;
	int			i;
	int			sign;

	return_value = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	get_sign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		return_value *= 10;
		return_value += nptr[i++] - '0';
	}
	if (return_value > LLONG_MAX)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)((int64_t)return_value * sign));
}
