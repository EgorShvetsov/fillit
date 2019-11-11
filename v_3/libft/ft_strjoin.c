/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:37:00 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/13 17:02:08 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*zero(char *arr)
{
	arr = malloc(1);
	arr[0] = '\0';
	return (arr);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	char	*tmp;

	arr = NULL;
	if (s1 && s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (zero(arr));
		if (!(arr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
			return (NULL);
		tmp = arr;
		while (*s1)
			*arr++ = *s1++;
		while (*s2)
			*arr++ = *s2++;
		*arr = '\0';
		return (tmp);
	}
	return (NULL);
}
