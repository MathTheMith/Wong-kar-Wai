/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:50:54 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 09:35:32 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_str_len(int64_t n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int64_t	get_power_of_ten(int64_t n)
{
	int64_t	power_of_ten;

	if (n < 0)
		n = -n;
	power_of_ten = 1;
	while (n > 9)
	{
		n /= 10;
		power_of_ten *= 10;
	}
	return (power_of_ten);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int64_t		power_of_ten;
	int64_t		tmp;

	tmp = (int64_t)n;
	str = malloc(sizeof(char) * (get_str_len(tmp) + 1));
	if (!str)
		return (NULL);
	power_of_ten = get_power_of_ten(tmp);
	i = 0;
	if (tmp < 0)
	{
		str[0] = '-';
		i = 1;
		tmp = -tmp;
	}
	while (power_of_ten > 0)
	{
		str[i++] = '0' + tmp / power_of_ten;
		tmp %= power_of_ten;
		power_of_ten /= 10;
	}
	str[i] = '\0';
	return (str);
}
