/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:09:54 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/29 16:10:01 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_tab[19][8] = {{0, 0, 1, 0, 2, 0, 3, 0}, {0, 0, 0, 1, 0, 2, 0, 3},
	{0, 0, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 2, 0, 2, 1},
	{0, 0, 0, 1, 1, 1, 2, 1}, {0, 0, 0, 1, 0, 2, 1, 0},
	{0, 2, 1, 0, 1, 1, 1, 2}, {0, 0, 0, 1, 1, 0, 2, 0},
	{0, 0, 1, 0, 2, 0, 2, 1}, {0, 0, 1, 0, 1, 1, 1, 2},
	{0, 0, 0, 1, 0, 2, 1, 2}, {0, 0, 1, 0, 1, 1, 2, 1},
	{0, 1, 0, 2, 1, 0, 1, 1}, {0, 1, 1, 0, 1, 1, 2, 0},
	{0, 0, 0, 1, 1, 1, 1, 2}, {0, 1, 1, 0, 1, 1, 1, 2},
	{0, 1, 1, 0, 1, 1, 2, 1}, {0, 0, 1, 0, 1, 1, 2, 0},
	{0, 0, 0, 1, 0, 2, 1, 1}};

void			type_to_tab_second(t_tetr *list)
{
	if (list->fig == 57856)
		ft_memcpy(list->fig_tab, g_tab[10], sizeof(int) * 8);
	else if (list->fig == 35904)
		ft_memcpy(list->fig_tab, g_tab[11], sizeof(int) * 8);
	else if (list->fig == 27648)
		ft_memcpy(list->fig_tab, g_tab[12], sizeof(int) * 8);
	else if (list->fig == 19584)
		ft_memcpy(list->fig_tab, g_tab[13], sizeof(int) * 8);
	else if (list->fig == 50688)
		ft_memcpy(list->fig_tab, g_tab[14], sizeof(int) * 8);
	else if (list->fig == 19968)
		ft_memcpy(list->fig_tab, g_tab[15], sizeof(int) * 8);
	else if (list->fig == 19520)
		ft_memcpy(list->fig_tab, g_tab[16], sizeof(int) * 8);
	else if (list->fig == 35968)
		ft_memcpy(list->fig_tab, g_tab[17], sizeof(int) * 8);
	else if (list->fig == 58368)
		ft_memcpy(list->fig_tab, g_tab[18], sizeof(int) * 8);
}

void			type_to_tab_first(t_tetr *list)
{
	if (list->fig == 34952)
		ft_memcpy(list->fig_tab, g_tab[0], sizeof(int) * 8);
	else if (list->fig == 61440)
		ft_memcpy(list->fig_tab, g_tab[1], sizeof(int) * 8);
	else if (list->fig == 52224)
		ft_memcpy(list->fig_tab, g_tab[2], sizeof(int) * 8);
	else if (list->fig == 17600)
		ft_memcpy(list->fig_tab, g_tab[3], sizeof(int) * 8);
	else if (list->fig == 50240)
		ft_memcpy(list->fig_tab, g_tab[4], sizeof(int) * 8);
	else if (list->fig == 59392)
		ft_memcpy(list->fig_tab, g_tab[5], sizeof(int) * 8);
	else if (list->fig == 11776)
		ft_memcpy(list->fig_tab, g_tab[6], sizeof(int) * 8);
	else if (list->fig == 51328)
		ft_memcpy(list->fig_tab, g_tab[7], sizeof(int) * 8);
	else if (list->fig == 35008)
		ft_memcpy(list->fig_tab, g_tab[8], sizeof(int) * 8);
	else if (list->fig == 36352)
		ft_memcpy(list->fig_tab, g_tab[9], sizeof(int) * 8);
	else
		type_to_tab_second(list);
}

int				types(int fig)
{
	if (fig != 34952 && fig != 61440 && fig != 52224 &&
		fig != 17600 && fig != 50240 && fig != 59392 &&
		fig != 11776 && fig != 51328 && fig != 35008 &&
		fig != 36352 && fig != 57856 && fig != 35904 &&
		fig != 27648 && fig != 19584 && fig != 50688 &&
		fig != 19968 && fig != 19520 && fig != 35968 &&
		fig != 58368)
		return (0);
	else
		return (1);
}

int				list_validation(t_tetr **head)
{
	t_tetr		*list;

	list = *head;
	while (list)
	{
		if (list->fig == 0)
			return (0);
		while (!(types(list->fig)) && list->fig < 61441)
			list->fig = list->fig << 1;
		if (list->fig > 61441)
			return (0);
		type_to_tab_first(list);
		list = list->next;
		if (list == *head)
			break ;
	}
	if ((*head)->prev->fig_num > 25)
		return (0);
	return (1);
}
