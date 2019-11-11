/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:33:59 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/30 16:34:01 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		one_pos(int **map, t_tetr **list, t_tetr **head)
{
	if (((*list)->fig_tab[7] < (*map)[7]) &&
			((*list)->fig_tab[5] < (*map)[7]) &&
				((*list)->fig_tab[3] < (*map)[7]) &&
					((*list)->fig_tab[1] < (*map)[7]))
	{
		(*list)->next->fig_tab[1] = (*list)->fig_tab[1] + 1;
		(*list)->next->fig_tab[3] = (*list)->fig_tab[3] + 1;
		(*list)->next->fig_tab[5] = (*list)->fig_tab[5] + 1;
		(*list)->next->fig_tab[7] = (*list)->fig_tab[7] + 1;
		(*list)->next->fig_tab[0] = (*list)->fig_tab[0];
		(*list)->next->fig_tab[2] = (*list)->fig_tab[2];
		(*list)->next->fig_tab[4] = (*list)->fig_tab[4];
		(*list)->next->fig_tab[6] = (*list)->fig_tab[6];
	}
	else
	{
		(*list)->next->fig_tab[1] = (*head)->fig_tab[1];
		(*list)->next->fig_tab[3] = (*head)->fig_tab[3];
		(*list)->next->fig_tab[5] = (*head)->fig_tab[5];
		(*list)->next->fig_tab[7] = (*head)->fig_tab[7];
		(*list)->next->fig_tab[0] = (*list)->fig_tab[0] + 1;
		(*list)->next->fig_tab[2] = (*list)->fig_tab[2] + 1;
		(*list)->next->fig_tab[4] = (*list)->fig_tab[4] + 1;
		(*list)->next->fig_tab[6] = (*list)->fig_tab[6] + 1;
	}
}

static int		comparing(int **map, t_tetr *list)
{
	int			i;

	i = 1;
	while (i <= 7)
	{
		if ((list->fig_tab[6] == (*map)[6] && list->fig_tab[i] == (*map)[7]) ||
			list->fig_tab[i] > (*map)[7] || list->fig_tab[6] > (*map)[6])
			return (0);
		i += 2;
	}
	return (1);
}

static void		create_positions(int **map, t_tetr **head)
{
	t_tetr		*tmp;
	t_tetr		*tmp_pos;
	t_tetr		*zero_pos;

	tmp = *head;
	while (tmp)
	{
		tmp_pos = tmp;
		zero_pos = tmp;
		tmp = tmp->next;
		while (tmp_pos)
		{
			if (comparing(map, tmp_pos))
			{
				tmp_pos->next = add_fig_pos(tmp_pos, tmp);
				one_pos(map, &tmp_pos, &zero_pos);
			}
			tmp_pos = tmp_pos->next;
			if (tmp_pos == tmp)
				break ;
		}
		if (tmp == *head)
			break ;
	}
}

void			solution(int **map, t_tetr **head, t_tetr **sol_matr)
{
	create_map(map, head);
	lst_copy(head, sol_matr);
	create_positions(map, sol_matr);
	if (!(solver(sol_matr, sqr_checker(head), map)))
		solution(map, head, sol_matr);
	else
	{
		print_solution(sol_matr, (*map)[7]);
	}
}
