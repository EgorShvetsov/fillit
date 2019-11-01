/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:12:17 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/13 16:24:41 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*arr;

	if (len + 1 == 0)
		return (NULL);
	if (!s || !(arr = malloc(len + 1)))
		return (NULL);
	ft_strncpy(arr, (char *)&s[start], len);
	arr[len] = '\0';
	return (arr);
}
