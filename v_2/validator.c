/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:21:18 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/29 16:21:21 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		reading(char *file, char **str)
{
	int			fd;
	int			ret;
	char		buf[100];
	char		*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buf, 99)))
	{
		buf[ret] = '\0';
		if (!*str)
			*str = ft_strdup(buf);
		else
		{
			tmp = *str;
			*str = ft_strjoin(tmp, buf);
			free(tmp);
		}
	}
	close(fd);
	if (!*str)
		return (0);
	return (1);
}

static int		to_bit(char *str)
{
	int			n;
	int			sim;

	n = 0;
	sim = 0;
	if ((ft_strlen(str) + 1) % 21 != 0)
		return (0);
	while (*str)
	{
		if (*str == '.' || *str == '#')
			sim++;
		else if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		else if (*str == '\n')
		{
			if (sim % 4 == 0 && sim % (n + 1) == 0 && sim != 0)
				n++;
			else if (*(str - 1) == '\n' && *(str - 2) != '\n')
				n = n + 0;
			else
				return (0);
		}
		str++;
	}
	return (1);
}

static void		make_list(int fig, t_tetr **head)
{
	t_tetr		*list;

	if (!*head)
	{
		*head = new_list();
		(*head)->fig = fig;
	}
	else
	{
		list = add_list(head);
		list->fig = fig;
	}
}

static void		to_list(char *str, t_tetr **head)
{
	int			fig;
	int			i;

	fig = 0;
	i = 0;
	while (*str)
	{
		if (*str == '.' || *str == '#')
			i++;
		if (*str == '#')
			fig = fig + (1 << (16 - i));
		if (*str == '\n')
			if (*(str - 1) == '\n' || *(str + 1) == '\0')
			{
				make_list(fig, head);
				fig = 0;
				i = 0;
			}
		str++;
	}
}

int				validator(char *file, t_tetr **head)
{
	char		*str;

	str = NULL;
	if (!(reading(file, &str)))
		return (0);
	if (!(to_bit(str)))
	{
		free(str);
		return (0);
	}
	to_list(str, head);
	if (!(list_validation(head)))
	{
		lst_del(head);
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
