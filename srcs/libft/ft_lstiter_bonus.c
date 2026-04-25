/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:43:49 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 10:45:05 by vquetier         ###   ########lyon.fr   */
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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*check_value;

	if (!lst || !f)
		return ;
	check_value = NULL;
	if (is_cycle(lst))
		check_value = lst;
	while (lst && lst->next != check_value)
	{
		f(lst->content);
		lst = lst->next;
	}
	if (lst)
		f(lst->content);
}
