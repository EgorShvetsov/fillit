/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:13:49 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/14 17:14:48 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	while (s[i] != (char)c && i != 0)
		i--;
	if (i == 0 && s[i] != (char)c)
		return (NULL);
	else
		return ((char *)&s[i]);
}
