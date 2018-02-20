/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:00:33 by dborysen          #+#    #+#             */
/*   Updated: 2018/02/12 14:00:35 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct	s_coord
{
	int				rows;
	int				cols;
	int				p_rows;
	int				p_cols;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_map
{
	char	**piece;
	char	**field;
}				t_map;

typedef struct	s_structs
{
	t_coord *last_coord;
	t_coord *fin_coord;
	t_coord *area;
}				t_structs;

char	*g_type;
int		g_i;

void			ft_field_area(char **line, t_coord *field);
void			ft_piece_area(char **line, t_coord *piece);
void			ft_wich_g_type(char **line, char **g_type);
void			ft_newnode(t_coord **head, int y, int x);
void			ft_lst_del(t_coord **head);
void			ft_possible_coord(t_map *map, t_coord **pos_coord);
int				ft_if_cover_one(char **field_map, char **piece_map,
								t_coord tmp, t_coord area);
void			ft_possible_coord2(t_coord area, t_coord crd, t_map *map,
								t_coord ***pos_coord);
char			**field_save(t_coord *area, t_coord **last_coord,
							char ***field_dup, char **line);
char			**piece_save(t_coord *area);
int				ft_modul(int n);
t_coord			ft_count_area(char **field_map, char **piece_map);
t_coord			*opp_last_peace(char **field_map, char **map_dup,
								t_coord *map, char *g_type);
t_coord			*get_right_coord(t_coord *head, int n);
t_coord			*find_pos_coord(t_coord *head, t_coord *op);

#endif
