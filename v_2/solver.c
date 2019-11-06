/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:09:45 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/05 16:09:47 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		show_lines(t_tetr *list, t_tetr **sol_matr)
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

static void		hide_one_line(t_tetr *hider)
{
	t_tetr		*tmp;

	tmp = hider;
	while (tmp)
	{
		if (tmp->fig == 0)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		tmp = tmp->pos_next;
		if (tmp == hider)
			break ;
	}
}

static void		lines_hider(t_tetr *list)
{
	t_tetr		*hider;

	hider = list->next;
	while (hider != list)
	{
		if (hider->important_indicator == 1 || hider->fig_num == list->fig_num)
			hide_one_line(hider);
		hider = hider->next;
	}
}

static void 	find_solution(t_tetr *list)
{
	t_tetr		*tmp;
	t_tetr		*tmp_line;

	tmp = list->pos_next;
	while (tmp)
	{
		tmp_line = tmp;
		while (tmp_line)
		{
			if (tmp_line->important_indicator == 1)
				lines_hider(tmp_line);
			tmp_line = tmp_line->pos_next;
			if (tmp_line == tmp)
				break ;
		}
		tmp = tmp->next;
		if (tmp == list->pos_next)
			break ;
	}
}

int 			solver(t_tetr **sol_matr)
{
	t_tetr		*tmp;

	tmp = *sol_matr;
	while (tmp)
	{
		find_solution(tmp);
		if (!(check_solution(tmp, sol_matr)))
		{
			show_lines(tmp, sol_matr);
			if (tmp->fig_num == 0 && tmp->next->fig_num == 1)
				return (0);
			hide_one_line(tmp);
			tmp = tmp->next;
		}
		else
		{
			if (lines_calc(tmp, (*sol_matr)->prev->fig_num))
				break ;
			else
				tmp = tmp->next;
		}
	}
	(*sol_matr) = tmp;
	return (1);
}
