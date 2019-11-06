/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:17:45 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/30 19:17:48 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		alloc_map(int **map, t_tetr **head)
{
	int			fig_sqr;
	int			i;

	i = 2;
	fig_sqr = ((*head)->prev->fig_num + 1) * 4;
	*map = malloc(sizeof(int) * 8);
	while (i * i < fig_sqr)
		i++;
	if ((*head)->fig_tab[6] > i)
		i = (*head)->fig_tab[6] + 1;
	else if ((*head)->fig_tab[7] > i)
		i = (*head)->fig_tab[7] + 1;
	(*map)[0] = 0;
	(*map)[1] = 0;
	(*map)[2] = 0;
	(*map)[3] = i - 1;
	(*map)[4] = i - 1;
	(*map)[5] = 0;
	(*map)[6] = i - 1;
	(*map)[7] = i - 1;
}

void			create_map(int **map, t_tetr **head)
{
	if (!*map)
		alloc_map(map, head);
	else
	{
		(*map)[3] = (*map)[3] + 1;
		(*map)[4] = (*map)[4] + 1;
		(*map)[6] = (*map)[6] + 1;
		(*map)[7] = (*map)[7] + 1;
	}
}
