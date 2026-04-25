/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:47:02 by vquetier          #+#    #+#             */
/*   Updated: 2025/11/12 11:25:31 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_and_return(t_list	**start, void (*del)(void *))
{
	ft_lstclear(start, del);
	return (NULL);
}

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

static t_list	**create_node(t_list *lst, t_list **current, void *(*f)(void *))
{
	void	*content;

	content = f(lst->content);
	if (!content)
		return (NULL);
	*current = ft_lstnew(content);
	if (!*current)
	{
		free(content);
		return (NULL);
	}
	return (current);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	**current;
	t_list	*check_value;

	if (!lst || !f || !del)
		return (NULL);
	check_value = NULL;
	if (is_cycle(lst))
		check_value = lst;
	start = NULL;
	current = &start;
	while (lst)
	{
		current = create_node(lst, current, f);
		if (!current)
			return (free_and_return(&start, del));
		lst = lst->next;
		current = &(*current)->next;
		if (lst == check_value)
			break ;
	}
	if (check_value)
		*current = start;
	return (start);
}
