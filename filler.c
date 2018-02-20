/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:54 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/24 14:46:55 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
*************************************************
**											   **
**	 			  FREE PART				       **
**											   **
*************************************************
*/

void		fin_free(t_coord **area, t_map **map,
					char ***p, t_coord **pos_coord)
{
	char **piece_map;

	piece_map = *p;
	free(*area);
	g_i = 0;
	while (piece_map[g_i])
		free(piece_map[g_i++]);
	free(piece_map);
	free(*map);
	ft_lst_del(&(*pos_coord));
}

void		find_type(void)
{
	char *line;

	g_i = 0;
	get_next_line(0, &line);
	ft_wich_g_type(&line, &g_type);
}

void		ret_fin_coord(t_coord *pos_coord, t_coord *last_coord)
{
	t_coord *fin_coord;

	fin_coord = find_pos_coord(pos_coord, last_coord);
	ft_putnbr(fin_coord->rows);
	ft_putstr(" ");
	ft_putnbr(fin_coord->cols);
	ft_putstr("\n");
}

int			main(void)
{
	char		*line;
	char		**f_d;
	t_map		*map;
	t_coord		*pos_coord;
	t_structs	*strct;

	f_d = NULL;
	find_type();
	while (get_next_line(0, &line) > 0)
	{
		pos_coord = NULL;
		if ((strct = (t_structs*)malloc(sizeof(t_structs))) == NULL ||
			(strct->area = (t_coord*)malloc(sizeof(t_coord))) == NULL ||
			(map = (t_map*)malloc(sizeof(t_map))) == NULL)
			return (0);
		ft_field_area(&line, strct->area);
		map->field = field_save(strct->area, &(strct->last_coord), &f_d, &line);
		ft_piece_area(&line, strct->area);
		map->piece = piece_save(strct->area);
		ft_possible_coord(map, &pos_coord);
		ret_fin_coord(pos_coord, strct->last_coord);
		fin_free(&(strct->area), &map, &(map->piece), &pos_coord);
		free(strct);
	}
	return (0);
}
