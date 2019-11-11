/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:11:46 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/14 17:20:04 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t i;

	i = 0;
	if (*small == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == *small && ft_strlen(small) <= len - i &&
				!(ft_strncmp((char *)&big[i],
						(char *)small, ft_strlen(small))))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
