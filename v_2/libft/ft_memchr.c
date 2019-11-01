/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:49:04 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/11 16:19:38 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	size_t				i;

	i = 0;
	a = s;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
			return ((void*)&a[i]);
		i++;
	}
	return (NULL);
}
