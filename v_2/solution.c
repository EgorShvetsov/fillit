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

/*static void		one_pos(int **map, t_tetr **list, t_tetr **head)
{
	if (((*list)->fig_tab[7] < (*map)[7]) && ((*list)->fig_tab[5] < (*map)[7]) &&
			((*list)->fig_tab[3] < (*map)[7]) && ((*list)->fig_tab[1] < (*map)[7]))
	{
		(*list)->pos_next->fig_tab[1] = (*list)->fig_tab[1] + 1;
		(*list)->pos_next->fig_tab[3] = (*list)->fig_tab[3] + 1;
		(*list)->pos_next->fig_tab[5] = (*list)->fig_tab[5] + 1;
		(*list)->pos_next->fig_tab[7] = (*list)->fig_tab[7] + 1;
		(*list)->pos_next->fig_tab[0] = (*list)->fig_tab[0];
		(*list)->pos_next->fig_tab[2] = (*list)->fig_tab[2];
		(*list)->pos_next->fig_tab[4] = (*list)->fig_tab[4];
		(*list)->pos_next->fig_tab[6] = (*list)->fig_tab[6];
	}
	else
	{
		(*list)->pos_next->fig_tab[1] = (*head)->fig_tab[1];
		(*list)->pos_next->fig_tab[3] = (*head)->fig_tab[3];
		(*list)->pos_next->fig_tab[5] = (*head)->fig_tab[5];
		(*list)->pos_next->fig_tab[7] = (*head)->fig_tab[7];
		(*list)->pos_next->fig_tab[0] = (*list)->fig_tab[0] + 1;
		(*list)->pos_next->fig_tab[2] = (*list)->fig_tab[2] + 1;
		(*list)->pos_next->fig_tab[4] = (*list)->fig_tab[4] + 1;
		(*list)->pos_next->fig_tab[6] = (*list)->fig_tab[6] + 1;
	}
}

static int		comparing(int **map, t_tetr *list)
{
	int			i;

	i = 1;
	while (i <= 7)
	{
		if ((list->fig_tab[6] == (*map)[6] && list->fig_tab[i] == (*map)[7]) ||
				list->fig_tab[i] > (*map)[7])
			return (0);
		i += 2;
	}
	return (1);
}

static void		create_positions(int **map, t_tetr **head)
{
	t_tetr		*tmp;
	t_tetr		*tmp_pos;

	tmp = *head;
	while (tmp)
	{
		tmp_pos = tmp;
		while (tmp_pos)
		{
			if (comparing(map, tmp_pos))
			{
				tmp_pos->pos_next = add_fig_pos(tmp);
				one_pos(map, &tmp_pos, &tmp);
			}
			tmp_pos = tmp_pos->pos_next;
			if (tmp_pos == tmp)
				break ;
		}
		tmp = tmp->next;
		if (tmp == *head)
			break ;
	}
}*/

static void		one_pos(int **map, t_tetr **list, t_tetr **head)
{
	if (((*list)->fig_tab[7] < (*map)[7]) && ((*list)->fig_tab[5] < (*map)[7]) &&
		((*list)->fig_tab[3] < (*map)[7]) && ((*list)->fig_tab[1] < (*map)[7]))
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
	/*int i = 0;
	  ft_putstr("map is:   ");
	while (i < 8)
		ft_putnbr((*map)[i++]);
	ft_putchar('\n');*/


	lst_copy(head, sol_matr);
	create_positions(map, sol_matr);
	create_matrix(map, sol_matr);



	/*
	 *
	 * Тест ссылок по карте. Надеюсь увидеть корректно расставленные единички
	 *
	 * Линии расставлены корректно.
	 *
	 */
	/*t_tetr *tmp;
	t_tetr *tmp_m = *sol_matr;
	while (tmp_m)
	{
		tmp = tmp_m->pos_next;
		while (tmp != tmp_m)
		{
			ft_putnbr(tmp->important_indicator);
			tmp = tmp->pos_next;
		}
		ft_putchar('\n');
		tmp_m = tmp_m->next;
		if (tmp_m == *sol_matr)
			break ;
	}*/


	/*
	 * Тест корректрости связывания столбцов
	 *
	 */

	t_tetr *tmp;
	tmp = (*sol_matr)->pos_next->pos_next;
	while (tmp)
	{
		ft_putnbr(tmp->important_indicator);
		ft_putchar('\n');
		tmp = tmp->next;
		if (tmp == (*sol_matr)->pos_next->pos_next)
			break ;
	}



/*
 * Тест количества положений
 *
 */
	/*int k = 0;
	int f;
	t_tetr		*tmp = *sol_matr;
	while (tmp)
	{
		f = 0;
		while (f < 8)
			ft_putnbr(tmp->fig_tab[f++]);
		ft_putchar('\n');
		tmp = tmp->next;
		k++;
		if (tmp == *sol_matr)
			break ;
	}
	ft_putstr("\nNumber of positions is ");
	ft_putnbr(k);*/


	/*ft_putstr("\n\nPositions of first fig is:\n");
	t_tetr *tmp = *head;
	t_tetr *tmp_v;
	int k;
	int kol;
	while (tmp)
	{
		tmp_v = tmp;
		kol = 0;
		while (tmp_v)
		{
			k = 0;
			while (k <= 7)
				ft_putnbr(tmp_v->fig_tab[k++]);
			ft_putchar('\n');
			tmp_v = tmp_v->pos_next;
			kol++;
			if (tmp_v == tmp)
				break ;
		}
		ft_putnbr(kol);
		ft_putstr("\n\nsecond fig\n");
		tmp = tmp->next;
		if (tmp == *head)
			break ;
	}*/
}
