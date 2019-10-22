/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:04:51 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/22 13:04:54 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		alloc_map(t_tetr *list, int **map)
{
	int			fig_sqr;
	int			i;

	i = 1;
	fig_sqr = (list->fig_num + 1) * 4;
	*map = malloc(sizeof(int) * 8);
	while (i * i < fig_sqr)
		i++;
	(*map)[0] = 0;
	(*map)[1] = 0;
	(*map)[2] = 0;
	(*map)[3] = i - 1;
	(*map)[4] = i - 1;
	(*map)[5] = 0;
	(*map)[6] = i - 1;
	(*map)[7] = i - 1;
}

static void 	make_map(int **map, t_tetr **head)
{
	t_tetr		*list;

	list = *head;
	if (!*map)
	{
		while (list->next != *head)
			list = list->next;
		alloc_map(list, map);
	}
	else
	{
		((*map)[3])++;
		((*map)[4])++;
		((*map)[6])++;
		((*map)[7])++;
	}
}

void			solution(t_tetr **head)
{
	static int	*map;
	int i;

	i = 0;
	make_map(&map, head);
	while (i != 8)
		ft_putnbr(map[i++]);
}
