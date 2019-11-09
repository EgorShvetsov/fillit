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
	if (list->fig_num == 0)
	{
		while (hider != list)
		{
			if (hider->important_indicator == 1 ||
					hider->fig_num == list->fig_num)
				hide_one_line(hider);
			hider = hider->next;
		}
	}
	else
	{
		while (hider->fig_num != 0)
		{
			if (hider->important_indicator == 1 ||
					hider->fig_num == list->fig_num)
				hide_one_line(hider);
			hider = hider->next;
		}
	}
}

static void		find_solution(t_tetr *list)
{
	t_tetr		*tmp_line;

	tmp_line = list->pos_next;
	if (list->fig_num != 0)
		find_solution(list->pos_next->prev->pos_prev);
	while (tmp_line)
	{
		if (tmp_line->important_indicator == 1)
			lines_hider(tmp_line);
		tmp_line = tmp_line->pos_next;
		if (tmp_line == list->pos_next)
			break ;
	}
}

static t_tetr	*magic(t_tetr *tmp, t_tetr **sol_matr)
{
	t_tetr		*to_hide;

	if (tmp->fig_num == 0)
	{
		show_lines(tmp->next, sol_matr);
		hide_one_line(tmp);
		tmp = tmp->next;
	}
	else
	{
		to_hide = tmp;
		tmp = tmp->pos_next->prev->pos_prev;
		show_lines(to_hide->next, sol_matr);
		hide_one_line(to_hide);
	}
	return (tmp);
}

int				solver(t_tetr **sol_matr, int sqr)
{
	t_tetr		*tmp;

	tmp = *sol_matr;
	if (!(indicators_calc(sol_matr)))
		return (0);
	while (tmp)
	{
		find_solution(tmp);
		if (!(check_solution(tmp, sol_matr)))
		{
			if ((tmp->fig_num == 0 && tmp->next->fig_num == 1) || sqr)
				return (0);
			tmp = magic(tmp, sol_matr);
		}
		else
		{
			if (lines_calc(tmp, (*sol_matr)->prev->fig_num) &&
					tmp->fig_num == (*sol_matr)->prev->fig_num)
				break ;
			else
				tmp = tmp->pos_next->next->pos_prev;
		}
	}
	(*sol_matr) = tmp;
	return (1);
}
