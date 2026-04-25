/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:34:37 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 09:37:53 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int64_t	power_of_ten;
	int64_t	tmp;

	if (fd <= ERR_FD)
		return ;
	tmp = (int64_t)n;
	power_of_ten = get_power_of_ten(tmp);
	if (tmp < 0)
	{
		tmp = -tmp;
		if (write(fd, "-", 1) == ERR_INT)
			return ;
	}
	while (power_of_ten > 0)
	{
		c = '0' + tmp / power_of_ten;
		tmp %= power_of_ten;
		power_of_ten /= 10;
		if (write(fd, &c, 1) == ERR_INT)
			return ;
	}
}
