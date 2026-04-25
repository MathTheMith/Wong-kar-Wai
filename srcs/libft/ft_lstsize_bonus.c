/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:19:38 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/10 18:04:35 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_cycle(t_list *lst)
{
	t_list	*slow;
	t_list	*fast;

	if (!lst)
		return (false);
	slow = lst;
	fast = lst->next;
	while (fast && fast->next)
	{
		if (slow == fast)
			return (true);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (false);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (is_cycle(lst))
		return (ERR_INT);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
