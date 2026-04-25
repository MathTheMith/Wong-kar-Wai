/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:30:40 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 10:21:42 by vquetier         ###   ########lyon.fr   */
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || is_cycle(*lst))
		return ;
	while (*lst)
		lst = &(*lst)->next;
	*lst = new;
}
