/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:29:42 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/23 11:29:46 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				ft_gnllist(int fd, t_gnllist **head, t_gnllist **list)
{
	if (!*head)
	{
		if (!(*head = malloc(sizeof(t_gnllist))))
			return (0);
		(*head)->file_d = fd;
		(*head)->next = NULL;
		(*head)->tail = NULL;
	}
	*list = *head;
	while ((*list)->file_d != fd && (*list)->next)
		(*list) = (*list)->next;
	if ((*list)->file_d == fd)
		return (1);
	else
	{
		if (!((*list)->next = malloc(sizeof(t_gnllist))))
			return (0);
		(*list)->next->file_d = fd;
		(*list)->next->next = NULL;
		(*list)->next->tail = NULL;
		*list = (*list)->next;
		return (1);
	}
}

static void				ft_join(t_gnllist **list)
{
	(*list)->buf[(*list)->ret] = '\0';
	if (!(*list)->tail)
		(*list)->tail = ft_strdup((*list)->buf);
	else
	{
		(*list)->copy = (*list)->tail;
		(*list)->tail = ft_strjoin((*list)->copy, (*list)->buf);
		free((*list)->copy);
	}
}

static void				ft_separator(t_gnllist **list, char **line, int *i)
{
	char				*tmp;
	char				*ptr;

	if (!(*list)->tail)
		(*list)->tail = ft_strdup("\0");
	tmp = ft_strchr((*list)->tail, '\n');
	if (!tmp)
	{
		*line = ft_strdup((*list)->tail);
		free((*list)->tail);
		(*list)->tail = NULL;
	}
	else
	{
		*i = 1;
		*line = ft_strsub((*list)->tail, 0, tmp - (*list)->tail + 1);
		ptr = *line;
		while (*ptr != '\n' && *ptr != '\0')
			ptr++;
		*ptr = '\0';
		(*list)->copy = ft_strdup(tmp + 1);
		free((*list)->tail);
		(*list)->tail = (*list)->copy;
	}
}

int						get_next_line(const int fd, char **line)
{
	static t_gnllist	*head;
	t_gnllist			*list;
	char				*tmp;
	int					very_important_i;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(ft_gnllist(fd, &head, &list)))
		return (-1);
	tmp = NULL;
	very_important_i = 0;
	while ((list->ret = read(fd, list->buf, BUFF_SIZE)))
	{
		if (list->ret < 0)
			return (-1);
		ft_join(&list);
		if ((tmp = ft_strchr(list->buf, '\n')))
			break ;
	}
	ft_separator(&list, line, &very_important_i);
	if (list->ret == 0 && ft_strlen(*line) == 0 && very_important_i == 0)
		return (0);
	return (1);
}
