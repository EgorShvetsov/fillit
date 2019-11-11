/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqr_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:17:01 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/09 17:17:04 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			sqr_checker(t_tetr **head)
{
	t_tetr	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		if (tmp->fig != 52224)
			return (0);
		tmp = tmp->next;
		if (tmp == *head)
			break ;
	}
	return (1);
}
