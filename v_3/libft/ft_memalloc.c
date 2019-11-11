/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:01:41 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/13 11:55:28 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *allocated_memory;

	if (!(allocated_memory = malloc(size)))
		return (NULL);
	ft_bzero(allocated_memory, size);
	return (allocated_memory);
}
