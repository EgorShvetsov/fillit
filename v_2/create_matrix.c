/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:37:02 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/01 18:37:04 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		create_elem(t_tetr *list, int i, int max_map)
{
	t_tetr		*tmp;
	int 		k;

	k = 1;
	tmp = list;
	while (tmp->pos_next != list)
		tmp = tmp->pos_next;
	tmp->pos_next = new_list();
	tmp->pos_next->fig = 0;
	tmp->pos_next->fig_num = list->fig_num;
	tmp->pos_next->pos_prev = tmp;
	tmp->pos_next->pos_next = list;
	list->pos_prev = tmp->pos_next;
	while (k < 8)
	{
		if ((max_map + 1) * list->fig_tab[k - 1] + list->fig_tab[k] == i)
			tmp->pos_next->important_indicator = 1;
		k += 2;
	}
}

static void		create_lines(int **map, t_tetr **sol_matr)
{
	int			i;
	int 		nodes;
	t_tetr		*tmp;

	tmp = *sol_matr;
	nodes = ((*map)[7] + 1) * ((*map)[7] + 1);
	while (tmp)
	{
		i = 0;
		while (i < nodes)
			create_elem(tmp, i++, (*map)[7]);
		tmp = tmp->next;
		if (tmp == *sol_matr)
			break ;
	}
}

static void		create_columns(t_tetr **sol_matr)
{
	t_tetr		*tmp_first;
	t_tetr		*tmp_second;
	t_tetr		*f;
	t_tetr		*s;

	tmp_first = *sol_matr;
	tmp_second = (*sol_matr)->next;
	while (tmp_first)
	{
		f = tmp_first->pos_next;
		s = tmp_second->pos_next;
		while (f != tmp_first)
		{
			f->next = s;
			s->prev = f;
			f = f->pos_next;
			s = s->pos_next;
		}
		tmp_first = tmp_first->next;
		tmp_second = tmp_second->next;
		if (tmp_first == *sol_matr)
			break ;
	}
}

void			create_matrix(int **map, t_tetr **sol_matr)
{
	create_lines(map, sol_matr);
	create_columns(sol_matr);
}
