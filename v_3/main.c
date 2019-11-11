/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:06:21 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/29 16:06:23 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetr	*head;
	t_tetr	*sol_matr;
	int		*map;

	if (ac == 2)
	{
		if (!(validator(av[1], &head)))
			ft_putstr("error\n");
		else
		{
			solution(&map, &head, &sol_matr);
			lst_del(&head);
			free(map);
			lst_del(&sol_matr);
		}
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
