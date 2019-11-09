/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:07:37 by dorphan           #+#    #+#             */
/*   Updated: 2019/10/29 16:07:40 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/gnl/get_next_line.h"

typedef struct		s_tetr
{
	int				fig_num;
	int				fig;
	int				pos;
	int				important_indicator;
	int				pos_in_sol_matr;
	int				fig_tab[8];
	struct s_tetr	*pos_next;
	struct s_tetr	*pos_prev;
	struct s_tetr	*prev;
	struct s_tetr	*next;
}					t_tetr;

int					types(int fig);
int					validator(char *file, t_tetr **head);
t_tetr				*new_list(void);
t_tetr				*add_list(t_tetr **head);
void				lst_del(t_tetr **head);
int					list_validation(t_tetr **head);
void				type_to_tab_first(t_tetr *list);
void				solution(int **map, t_tetr **head, t_tetr **sol_matr);
void				create_map(int **map, t_tetr **head);
t_tetr				*add_fig_pos(t_tetr *fig_pos, t_tetr *head);
void				lst_copy(t_tetr **head, t_tetr **sol_matr);
void				create_matrix(int **map, t_tetr **sol_matr);
int					sqr_checker(t_tetr **head);
int					solver(t_tetr **sol_matr, int sqr);
int					indicators_calc(t_tetr **sol_matr);
int					check_solution(t_tetr *list, t_tetr **sol_matr);
void				show_lines(t_tetr *list, t_tetr **sol_matr);
void				print_solution(t_tetr **sol_matr, int i);
int					lines_calc(t_tetr *list, int k);

#endif
