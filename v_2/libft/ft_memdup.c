/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:33:41 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/17 17:34:03 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memdup(void *src, size_t size)
{
	unsigned char	*str;
	size_t			i;

	if (!(str = malloc(size)))
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
