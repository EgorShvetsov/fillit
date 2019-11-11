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
	hider->prev->next = hider->next;
}

static void		lines_hider(t_tetr *list, int y, int x)
{
	t_tetr		*hider;
	t_tetr		*tmp;
	int			i;

	hider = list->next;
	while (hider != list)
	{
		i = 0;
		while (i < 7)
		{
			if ((hider->fig_tab[i] == y && hider->fig_tab[i + 1] == x) ||
				hider->fig_num == list->fig_num)
			{
				tmp = lst(hider);
				tmp->next = hider->next;
				break ;
			}
			i += 2;
		}
		hider = hider->next;
	}
}

static void		find_solution(t_tetr *list)
{
	int			i;

	i = 0;
	if (list->fig_num != 0)
		find_solution(lst(list));
	while (i < 7)
	{
		lines_hider(list, list->fig_tab[i], list->fig_tab[i + 1]);
		i += 2;
	}
}

static t_tetr	*magic(t_tetr *tmp, t_tetr **sol_matr)
{
	t_tetr		*to_hide;

	if (tmp->fig_num == 0)
	{
		show_lines(tmp, sol_matr);
		hide_one_line(tmp);
		tmp = tmp->next;
	}
	else
	{
		to_hide = tmp;
		tmp = lst(tmp);
		show_lines(to_hide, sol_matr);
		tmp->next = to_hide->next;
	}
	return (tmp);
}

int				solver(t_tetr **sol_matr, int sqr, int **map)
{
	t_tetr		*tmp;

	tmp = *sol_matr;
	if (!(indicators_calc(sol_matr, map)))
		return (0);
	while (tmp)
	{
		find_solution(tmp);
		if (!(check_solution(tmp, sol_matr)))
		{
			if ((tmp->fig_num == 0 && fail(tmp, sol_matr)) || sqr)
				return (0);
			tmp = magic(tmp, sol_matr);
		}
		else
		{
			if (lines_calc(tmp, (*sol_matr)->prev->fig_num) &&
					tmp->fig_num == (*sol_matr)->prev->fig_num)
				break ;
			else
				tmp = tmp->next;
		}
	}
	(*sol_matr) = tmp;
	return (1);
}
