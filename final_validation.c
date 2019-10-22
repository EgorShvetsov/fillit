/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:09:07 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/21 14:09:10 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		del_extra_dots(t_tetr **list)
{
	int			x;
	int			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		if (!(ft_strchr((*list)->fig[y], '#')))
			while (y < 4)
				ft_bzero((*list)->fig[y++], 4);
		else
		{
			while ((*list)->fig[y][x] != '#' && x < 4)
				x++;
			while ((*list)->fig[y][x] == '#' && x < 4)
				x++;
			while (x < 4)
				(*list)->fig[y][x++] = '\0';
			y++;
		}
	}
}

static int		hash_calc(t_tetr **list)
{
	int			x;
	int			y;
	int			result;

	y = 0;
	result = 0;
	while ((*list)->fig[y][0] != '\0' && y < 4)
	{
		x = 0;
		while ((*list)->fig[y][x] != '\0')
		{
			if ((*list)->fig[y][x] == '#')
				result++;
			x++;
			if ((x == 4 && result != 4) || ((x == 4 && result == 4 && y == 1)))
				result += 42;
		}
		y++;
	}
	return (result);
}

/*
 * Создание двумерного массива int состоящего из 0 и 1
 */

/*static void		char_to_int(t_tetr **list)
{
	int			x;
	int			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if ((*list)->fig[y][x] == '#')
				(*list)->fig_int[y][x++] = 1;
			else
				(*list)->fig_int[y][x++] = 0;
		}
		y++;
	}
}*/

static void		eight_digits(t_tetr **list)
{
	int			x;
	int			y;
	int			arr;

	y = 0;
	arr = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if ((*list)->fig[y][x] == '#')
			{
				(*list)->one_d_int[arr] = y;
				(*list)->one_d_int[arr + 1] = x;
				arr += 2;
			}
			x++;
		}
		y++;
	}
}

int				final_validation(t_tetr **head)
{
	t_tetr		*list;

	list = *head;
	while (list)
	{
		del_extra_dots(&list);
		if (hash_calc(&list) != 4)
			return (0);
		//char_to_int(&list);
		eight_digits(&list);
		list = list->next;
		if (list == *head)
			break ;
	}
	return (1);
}
