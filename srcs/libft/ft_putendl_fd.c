/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:31:15 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 09:37:45 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd <= ERR_FD || !s)
		return ;
	if (write(fd, s, ft_strlen(s)) == ERR_INT)
		return ;
	write(fd, "\n", 1);
}
