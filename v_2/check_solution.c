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

static void		print_sim(t_tetr *list)
{
	t_tetr		*print;

	print = list;
	while (print)
	{
		if (print->important_indicator == 1)
		{
			ft_putchar('A' + print->fig_num);
			break ;
		}
		print = print->next;
		if (print == list)
		{
			ft_putchar('.');
			break ;
		}
	}
}

void			print_solution(t_tetr **sol_matr, int i)
{
	t_tetr		*tmp;
	int 		num;

	num = 1;
	tmp = (*sol_matr)->pos_next;
	while (tmp != *sol_matr)
	{
		print_sim(tmp);
		if (num % i == 0)
			ft_putchar('\n');
		num++;
		tmp = tmp->pos_next;
	}
}

int 		lines_calc(t_tetr *list, int k)
{
	t_tetr	*tmp;
	int		i;

	i = 0;
	tmp = list->pos_next;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp->pos_prev == list)
			break ;
		i++;
	}
	if (i == k)
		return (1);
	return (0);
}

int 		check_solution(t_tetr *list, t_tetr **sol_matr)
{
	t_tetr	*tmp;
	int 	fig;

	tmp = list->pos_next;
	fig = 0;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp == list->pos_next)
			break ;
		if (tmp->fig_num != fig)
			fig++;
	}
	if (fig == (*sol_matr)->prev->fig_num)
		return (1);
	return (0);
}
