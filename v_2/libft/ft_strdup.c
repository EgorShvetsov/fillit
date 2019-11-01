/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:35:06 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/14 13:59:34 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*tmp;

	if (!(str = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	tmp = str;
	str = ft_strcpy(tmp, src);
	return (str);
}
