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

int				indicators_calc(t_tetr **sol_matr, int **map)
{
	t_tetr *tmp;

	tmp = *sol_matr;
	while (tmp)
	{
		if ((*map)[7] < tmp->fig_tab[0] || (*map)[7] < tmp->fig_tab[1] ||
			(*map)[7] < tmp->fig_tab[2] || (*map)[7] < tmp->fig_tab[3] ||
			(*map)[7] < tmp->fig_tab[4] || (*map)[7] < tmp->fig_tab[5] ||
			(*map)[7] < tmp->fig_tab[6] || (*map)[7] < tmp->fig_tab[7])
			return (0);
		tmp = tmp->next;
		if (tmp == *sol_matr)
			break ;
	}
	return (1);
}

int				fail(t_tetr *list, t_tetr **sol_matr)
{
	t_tetr		*tmp;

	tmp = *sol_matr;
	while (tmp != list)
	{
		if (tmp->prev == list && tmp->fig_num == 1)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

t_tetr			*lst(t_tetr *list)
{
	t_tetr		*tmp;

	tmp = list;
	while (tmp->next != list)
		tmp = tmp->next;
	return (tmp);
}

void			show_lines(t_tetr *list, t_tetr **sol_matr)
{
	t_tetr		*tmp;

	tmp = (*sol_matr)->prev;
	tmp->next = *sol_matr;
	while (tmp != list)
	{
		tmp->prev->next = tmp;
		tmp = tmp->prev;
	}
}
