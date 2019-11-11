/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:19:28 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/13 14:18:15 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*arr;
	size_t		i;
	size_t		k;
	size_t		d;

	if (!s)
		return (arr = NULL);
	i = 0;
	d = 0;
	k = ft_strlen((char *)s) - 1;
	while (s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
		k--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		arr = malloc(1);
	else
	{
		if (!(arr = malloc(k - i + 2)))
			return (NULL);
		while (i <= k)
			arr[d++] = s[i++];
	}
	arr[d] = '\0';
	return (arr);
}
