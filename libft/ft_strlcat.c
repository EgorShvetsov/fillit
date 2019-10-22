/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:36:37 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/12 14:07:12 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (dst[k] != '\0' && k < size)
		k++;
	if (k == size)
		return (size + (size_t)ft_strlen((char *)src));
	while (k < size - 1 && src[i] != '\0')
		dst[k++] = src[i++];
	if (k == size - 1)
		dst[k] = '\0';
	if (src[i] == '\0' && k < size)
	{
		dst[k] = '\0';
		return (k);
	}
	else
	{
		while (src[i++] != '\0')
			k++;
	}
	return (k);
}
