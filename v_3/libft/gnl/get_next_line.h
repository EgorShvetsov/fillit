/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:43:57 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/23 11:45:35 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libft.h"

typedef struct			s_gnllist
{
	int					file_d;
	int					ret;
	char				buf[BUFF_SIZE + 1];
	char				*tail;
	char				*copy;
	struct s_gnllist	*next;
}						t_gnllist;

int						get_next_line(const int fd, char **line);

#endif
