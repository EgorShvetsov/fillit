/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:34:57 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/17 13:34:59 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_tetrlist(t_tetr **head, t_tetr **list)
{
	if (!*head)
	{
		*head = malloc(sizeof(t_tetr));
		/*while (i < 4)
			ft_bzero((*head)->fig[i++], 5);*/
		(*head)->fig_num = 0;
		(*head)->next = *head;
		(*head)->prev = *head;
		*list = *head;
	}
	else
	{
		while ((*list)->next != *head)
			(*list) = (*list)->next;
		(*list)->next = malloc(sizeof(t_tetr));
		(*list)->next->fig_num = (*list)->fig_num + 1;
		(*list)->next->prev = *list;
		*list = (*list)->next;
		/*while (i < 4)
			ft_bzero((*list)->fig[i++], 5);*/
		(*list)->next = *head;
	}
	return (1);
}

static int		file_to_llist(t_tetr **head, int fd)
{
	char		*line;
	t_tetr		*list;
	int			i;
	int			k;

	i = 0;
	k = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (*line == '\0')
		{
			i = 0;
			k = 0;
		}
		if (i++ == 0)
			if (!(ft_tetrlist(head, &list)))
				return (0);
		if (*line != '\0')
			ft_strcpy(list->fig[k++], line);
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

static void		move_up(t_tetr **list)
{
	int			i;
	int			k;
	int			str;

	k = 0;
	i = 0;
	while (k < 4 && ft_strcmp((*list)->fig[k], "....") == 0)
		k++;
	while (k < 4 && k != i)
	{
		str = 0;
		ft_strcpy((*list)->fig[i++], (*list)->fig[k]);
		while ((*list)->fig[k][str])
			(*list)->fig[k][str++] = '.';
		k++;
	}
}

static void		move_left(t_tetr **list)
{
	int			y;
	int			x;

	x = 0;
	y = 0;
	while ((*list)->fig[y][x] != '#')
	{
		y++;
		if (y == 4)
		{
			y = 0;
			x++;
		}
	}
	y = 0;
	while (y < 4)
	{
		ft_strcpy((*list)->fig[y], &((*list)->fig[y][x]));
		if (x == 3)
			(*list)->fig[y][x] = '\0';
		y++;
	}
}

int				fig_validator(int fd, t_tetr **head)
{
	t_tetr		*list;

	if (!(file_to_llist(head, fd)))
		return (0);
	list = (*head);
	while (list)
	{
		move_up(&list);
		move_left(&list);
		list = list->next;
		if (list == *head)
			break ;
	}
	if (!final_validation(head))
		return (0);
	return (1);
}
