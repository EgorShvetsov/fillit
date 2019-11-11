/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:17:27 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/14 13:58:22 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (!a && !b)
		return (NULL);
	if (b >= a)
	{
		while (len-- != 0)
			b[len] = a[len];
	}
	else
		b = ft_memcpy(dst, src, len);
	return (b);
}
