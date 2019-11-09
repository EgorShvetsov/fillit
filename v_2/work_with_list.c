/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:27:44 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/29 19:27:48 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		del_positions(t_tetr *list)
{
	t_tetr		*tmp;

	tmp = list->pos_next;
	while (tmp != list)
	{
		tmp = tmp->pos_next;
		free(tmp->pos_prev);
	}
}

void			lst_del(t_tetr **head)
{
	t_tetr		*tmp;

	tmp = (*head)->next;
	del_positions(*head);
	while (tmp != *head)
	{
		del_positions(tmp);
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(*head);
}

t_tetr			*new_list(void)
{
	t_tetr		*list;

	if (!(list = malloc(sizeof(t_tetr))))
		return (NULL);
	list->important_indicator = 0;
	list->pos_in_sol_matr = 0;
	list->fig_num = 0;
	list->fig = 0;
	list->pos = 0;
	list->next = list;
	list->prev = list;
	list->pos_next = list;
	list->pos_prev = list;
	return (list);
}

t_tetr			*add_list(t_tetr **head)
{
	t_tetr		*tmp;

	tmp = *head;
	while (tmp->next != *head)
		tmp = tmp->next;
	tmp->next = new_list();
	tmp->next->fig_num = tmp->fig_num + 1;
	tmp->next->prev = tmp;
	tmp->next->next = *head;
	(*head)->prev = tmp->next;
	tmp = tmp->next;
	return (tmp);
}

t_tetr			*add_fig_pos(t_tetr *fig_pos, t_tetr *fig_next)
{
	fig_pos->next = new_list();
	fig_pos->next->prev = fig_pos;
	fig_pos->next->next = fig_next;
	fig_pos->next->fig_num = fig_pos->fig_num;
	fig_pos->next->fig = fig_pos->fig;
	fig_pos->next->pos = fig_pos->pos + 1;
	fig_next->prev = fig_pos->next;
	fig_pos = fig_pos->next;
	return (fig_pos);
}
