/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:18:26 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/16 11:51:17 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w_calc(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static char		*is_a_word(char *str, char c, int *ptr_g)
{
	int		i;
	int		k;
	char	*arr;
	int		f;

	i = 0;
	f = 0;
	while (str[i] == c)
		i++;
	k = i;
	while (str[k] != c && str[k] != '\0')
		k++;
	if (!(arr = malloc(k - i + 1)))
		return (NULL);
	while (i < k)
		arr[f++] = str[i++];
	arr[f] = '\0';
	*ptr_g += i;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		*ptr_g;
	int		i;
	int		k;
	int		g;

	if (!s)
		return (NULL);
	i = w_calc(s, c);
	k = 0;
	g = 0;
	ptr_g = &g;
	if (!(a = malloc(sizeof(*a) * (i + 1))))
		return (NULL);
	a[i] = NULL;
	while (k < i)
		if (!(a[k++] = is_a_word((char *)&s[g], c, ptr_g)))
		{
			while (k <= 0)
				free(a[k--]);
			free(a);
			return (NULL);
		}
	return (a);
}
