/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:41:55 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/17 15:42:11 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	if (!(new_list = f(lst)))
	{
		free(new_list);
		return (NULL);
	}
	first = new_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_list->next = f(lst)))
		{
			free(new_list->next);
			return (NULL);
		}
		new_list = new_list->next;
	}
	return (first);
}
