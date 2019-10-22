/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:11:30 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/14 13:11:34 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
 * Это тестовая функция. Её задача - распечатывать информацию из списка, в который я уже сохранил фигуры.
 */

int 	ft_listcalc(t_tetr *head)
{
	int i;
	t_tetr *tmp;

	i = 1;
	tmp = head;
	while (head->next != tmp)
	{
		head = head->next;
		i++;
	}
	return (i);
}

static void		give_colour(char *str, t_tetr *list)
{
	while (*str)
	{
		if (*str == '#')
			*str = 'A' + list->fig_num;
		str++;
	}
}

void	test_print(t_tetr *head)
{
	int i;
	int c_to_i;
	int one_arr;
	t_tetr *tmp;

	tmp = head;
	ft_putstr("\nValidator works well, so here we can see information from our list...\n\n");
	printf("Linked list consists of [%i] lists (from 1 to...)\n\n", ft_listcalc(head));
	while (head)
	{
		i = 0;
		one_arr = 0;
		printf("in list number [%i] we have:\n", head->fig_num);
		while (i < 4)
		{
			c_to_i = 0;
			give_colour(head->fig[i], head);
			ft_putstr(head->fig[i]);
			ft_putstr("\t\t");
			/*while (c_to_i < 4)
				ft_putnbr(head->fig_int[i][c_to_i++]);*/
			i++;
			ft_putstr("\t\t");
			while (one_arr <= 7)
				ft_putnbr(head->one_d_int[one_arr++]);
			ft_putchar('\n');
		}
		head = head->next;
		if (head == tmp)
			break ;
	}
}
/*
 * А вот эту функцию лучше не удалять... Тут я чищу список.
 */
static void		list_free(t_tetr *head)
{
	t_tetr *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
/*
 *
 *
 */

int		main(int ac, char **av)
{
	t_tetr	*head;


	if (ac == 2)
	{
		if (!(validator(av[1], &head)))
			ft_putstr("error\n");
		else
		{
			test_print(head);//тесты валидатора
			solution(&head);
			//list_free(head);
		}
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}