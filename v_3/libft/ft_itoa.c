/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:02:23 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/16 11:38:35 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static char		*transformator(char *str, int n)
{
	long i;

	i = n;
	if (i < 0)
	{
		i *= -1;
		str[0] = '-';
		str++;
	}
	if (i >= 10)
		transformator(str, i / 10);
	str[calc(i) - 1] = (i % 10) + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*arr;
	int		i;

	i = 0;
	if (!(arr = malloc(calc(n) + 1)))
		return (NULL);
	arr[calc(n)] = '\0';
	arr = transformator(&arr[i], n);
	if (n < 0)
		arr--;
	return (arr);
}
