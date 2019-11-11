/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:47:34 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/05 20:47:36 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		print_sim(t_tetr **sol_matr, int k, int map)
{
	t_tetr		*tmp;
	int			i;

	tmp = *sol_matr;
	while (tmp)
	{
		i = 0;
		while (i < 7)
		{
			if ((map + 1) * tmp->fig_tab[i] + tmp->fig_tab[i + 1] == k)
			{
				ft_putchar(tmp->fig_num + 'A');
				return (1);
			}
			i += 2;
		}
		tmp = tmp->next;
		if (tmp == *sol_matr)
			break ;
	}
	return (0);
}

void			print_solution(t_tetr **sol_matr, int i)
{
	int			k;

	k = 0;
	while (k != (i + 1) * (i + 1))
	{
		if (!(print_sim(sol_matr, k, i)))
			ft_putchar('.');
		if ((k + 1) % (i + 1) == 0)
			ft_putchar('\n');
		k++;
	}
}

int				lines_calc(t_tetr *list, int k)
{
	t_tetr		*tmp;
	int			i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp == list)
			break ;
		i++;
	}
	if (i == k)
		return (1);
	return (0);
}

int				check_solution(t_tetr *list, t_tetr **sol_matr)
{
	t_tetr		*tmp;
	t_tetr		*tmp_sc;
	int			i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp_sc = tmp;
		tmp = tmp->next;
		if (tmp == list)
			break ;
		if (tmp->fig_num != tmp_sc->fig_num)
			i++;
	}
	if (i == (*sol_matr)->prev->fig_num)
		return (1);
	return (0);
}
