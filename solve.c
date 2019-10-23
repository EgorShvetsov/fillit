/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:04:23 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/22 18:04:28 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void			one_position(t_tetr **pos, int y, int x)
{
	int				i;

	i = 0;
	while (i <= 7)
	{
		if (i % 2 == 0)
			(*pos)->one_d_int[i++] += y;
		else
			(*pos)->one_d_int[i++] += x;
	}
}

static void		make_list(t_tetr **fig, int y, int x)
{
	t_tetr			*pos;

	pos = *fig;
	while (pos)
	{
		if (pos->pos_next == *fig)
			break ;
		pos = pos->pos_next;
	}
	pos->pos_next = malloc(sizeof(t_tetr));
	pos->pos_next->pos_prev = pos;
	pos->pos_next->fig_num = pos->fig_num;
	ft_memcpy(pos->pos_next->one_d_int, (*fig)->one_d_int, sizeof(pos->one_d_int));
	pos = pos->pos_next;
	pos->pos_next = *fig;
	(*fig)->pos_prev = pos;
	pos->next = pos;
	pos->prev = pos;
	one_position(&pos, y, x);
}

static void			make_positions(int *map, t_tetr **head)
{
	int 			y;
	int 			x;
	t_tetr			*fig;

	fig = *head;
	y = 0;
	while (fig)
	{
		while (y + fig->one_d_int[6] <= map[7])
		{
			x = 0;
			while (x + fig->one_d_int[7] <= map[7])
			{
				if (x == 0 && y == 0)
					x++;
				make_list(&fig, y, x);
				x++;
			}
			y++;
		}
		fig = fig->next;
		if (fig == *head)
			break ;
	}
}

/*static void			make_four_ll(int *map, t_tetr **head)
{
	t_tetr			*fig;

	fig = *head;
}*/

int 				solve(int *map, t_tetr **head)
{
	t_tetr *tmp;
	t_tetr *tmp2;
	int i = 1;

	tmp = *head;
	make_positions(map, head);
	//make_four_ll(map, head);
	while (tmp)
	{
		tmp2 = tmp;
		while (tmp2)
		{
			printf("fig [%i] pos is [%i %i %i %i %i %i %i %i]\n", i, tmp2->one_d_int[0], tmp2->one_d_int[1], tmp2->one_d_int[2], tmp2->one_d_int[3], tmp2->one_d_int[4], tmp2->one_d_int[5], tmp2->one_d_int[6], tmp2->one_d_int[7]);
			tmp2 = tmp2->pos_next;
			if (tmp2 == tmp)
				break ;
		}
		tmp = tmp->next;
		i++;
		if (tmp == *head)
			break ;
	}
	return (1);
}
