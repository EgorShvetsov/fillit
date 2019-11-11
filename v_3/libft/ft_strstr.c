/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:21:48 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/11 10:20:52 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_comp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] != s1[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i - 1] - s1[i - 1]);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == *needle
				&& !(str_comp((char *)&haystack[i], (char *)needle)))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
