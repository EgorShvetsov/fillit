/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:37:20 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/15 15:37:24 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#	define FILLIT_H

# include "libft/libft.h"
# include "libft/gnl/get_next_line.h"

typedef struct		s_tetr
{
	int 			fig_num;
	char 			fig[4][5];
	//int 			fig_int[4][4];
	int 			one_d_int[8];
	struct s_tetr	*pos_next;
	struct s_tetr	*pos_prev;
	struct s_tetr	*prev;
	struct s_tetr	*next;
}					t_tetr;

int					validator(char *file, t_tetr **head);
int					fig_validator(int fd, t_tetr **head);
int					final_validation(t_tetr **head);
void				solution(t_tetr **head);

#endif
