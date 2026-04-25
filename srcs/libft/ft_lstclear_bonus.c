/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:39:16 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 10:38:53 by vquetier         ###   ########lyon.fr   */
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;
	t_list	*check_value;

	check_value = NULL;
	if (!lst || !del)
		return ;
	if (is_cycle(*lst))
		check_value = *lst;
	current = *lst;
	while (current && current->next != check_value)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	if (current)
	{
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
