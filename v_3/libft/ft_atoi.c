/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:22:48 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/26 11:21:38 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		is_too_much(unsigned long long result, int znak, int big)
{
	if (big > 19 && znak == 1)
		return (-1);
	else if (big > 19 && znak == -1)
		return (0);
	else if (result > 9223372036854775807 && znak == 1)
		return (-1);
	else if (result > 9223372036854775807 && znak == -1)
		return (0);
	else
		return ((int)result * znak);
}

int				ft_atoi(const char *str)
{
	size_t						i;
	unsigned long long int		result;
	int							znak;
	int							big;

	i = 0;
	result = 0;
	znak = 1;
	big = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+')
			&& str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		if (str[i] == '-')
			znak *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + ((unsigned long long int)str[i++] - '0');
		big++;
	}
	return (is_too_much(result, znak, big));
}
