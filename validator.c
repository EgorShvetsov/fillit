/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:03:59 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/16 13:04:01 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		line_validator(char *line, int *hash_calc)
{
	char		*tmp;

	tmp = line;
	while (*tmp != '\0')
	{
		if (*tmp != '.' && *tmp != '#')
			return (1);
		if (*tmp == '#')
			(*hash_calc)++;
		tmp++;
	}
	if (tmp - line != 4)
		return (1);
	return (0);
}

static int		sqr_validator(char **line, int *line_calc, int *hash_calc)
{
	if (**line != '\0')
	{
		if (line_validator(*line, hash_calc))
			return (0);
		(*line_calc)++;
	}
	else if (**line == '\0' && *line_calc != 4)
		return (0);
	else
	{
		*line_calc = 0;
		if (*hash_calc != 4)
			return (0);
		*hash_calc = 0;
	}
	return (1);
}

static int		reading(int fd)
{
	char		*line;
	int			line_calc;
	int			hash_calc;
	int			res;

	hash_calc = 0;
	line_calc = 0;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!(sqr_validator(&line, &line_calc, &hash_calc)))
			return (0);
		free(line);
	}
	if (res == 0)
		free(line);
	else
		return (0);
	return (1);
}

int				validator(char *file, t_tetr **head)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	if (!(reading(fd)))
		return (0);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	if (!(fig_validator(fd, head)))
		return (0);
	return (1);
}
