/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:06:28 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/09 19:06:31 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				indicators_calc(t_tetr **sol_matr)
{
	t_tetr		*tmp;
	t_tetr		*tmp_line;
	int			i;

	tmp = *sol_matr;
	while (tmp)
	{
		i = 0;
		tmp_line = tmp->pos_next;
		while (tmp_line != tmp)
		{
			if (tmp_line->important_indicator == 1)
				i++;
			tmp_line = tmp_line->pos_next;
		}
		if (i != 4)
			return (0);
		tmp = tmp->next;
		if (tmp == *sol_matr)
			break ;
	}
	return (1);
}

void			show_lines(t_tetr *list, t_tetr **sol_matr)
{
	t_tetr		*tmp_line;
	t_tetr		*tmp;

	tmp = list;
	while (tmp)
	{
		tmp_line = tmp->pos_next;
		while (tmp_line != tmp)
		{
			tmp_line->prev->next = tmp_line;
			tmp_line->next->prev = tmp_line;
			tmp_line = tmp_line->pos_next;
		}
		tmp = tmp->next;
		if (tmp == *sol_matr)
			break ;
	}
}
