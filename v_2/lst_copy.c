/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:09:07 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/01 16:09:09 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fig_cpy(t_tetr *src, t_tetr *dst)
{
	ft_memcpy(dst->fig_tab, src->fig_tab, sizeof(int) * 8);
	dst->fig = src->fig;
	dst->fig_num = src->fig_num;
}

void			lst_copy(t_tetr **head, t_tetr **sol_matr)
{
	t_tetr		*tmp;
	t_tetr		*tmp_sm;

	tmp = *head;
	if (*sol_matr)
	{
		lst_del(sol_matr);
		*sol_matr = NULL;
	}
	*sol_matr = new_list();
	fig_cpy(tmp, *sol_matr);
	tmp = tmp->next;
	tmp_sm = *sol_matr;
	if (tmp != *head)
	{
		while (tmp)
		{
			tmp_sm = add_list(sol_matr);
			fig_cpy(tmp, tmp_sm);
			tmp = tmp->next;
			if (tmp == *head)
				break;
		}
	}
}
