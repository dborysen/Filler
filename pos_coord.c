/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:06:11 by dborysen          #+#    #+#             */
/*   Updated: 2018/02/14 13:06:12 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
*************************************************
**											   **
**	CHECKING, IF STAR COVER EXTRA FIELD PIECE  **
**											   **
*************************************************
*/

int			ft_if_cover_one(char **field_map, char **piece_map,
						t_coord tmp, t_coord area)
{
	int px;
	int py;
	int fy;
	int fx;
	int covernum;

	covernum = 0;
	py = 0;
	px = 0;
	fy = tmp.rows;
	fx = tmp.cols;
	while (py < area.p_rows)
	{
		px = 0;
		while (px < area.p_cols)
		{
			if (piece_map[py][px] == '*' && (field_map[fy + py][fx + px] == 'X'
			|| field_map[fy + py][fx + px] == 'x' || field_map[fy + py][fx + px]
			== 'O' || field_map[fy + py][fx + px] == 'o'))
				covernum++;
			px++;
		}
		py++;
	}
	return (covernum == 1) ? 0 : -1;
}

/*
*************************************************
**											   **
**			SAVING POSSIBLE COORDINATES		   **
**											   **
*************************************************
*/

t_coord		ft_count_area(char **field_map, char **piece_map)
{
	t_coord area;

	area.rows = 0;
	area.cols = 0;
	area.p_rows = 0;
	area.p_cols = 0;
	while (field_map[area.rows][area.cols] != '\0')
		area.cols++;
	while (field_map[area.rows] != 0)
		area.rows++;
	while (piece_map[area.p_rows][area.p_cols] != '\0')
		area.p_cols++;
	while (piece_map[area.p_rows] != 0)
		area.p_rows++;
	return (area);
}

void		ft_possible_coord2(t_coord area, t_coord crd, t_map *map,
								t_coord ***pos_coord)
{
	char	pl;
	t_coord tmp;

	while (crd.p_rows < area.p_rows)
	{
		crd.p_cols = 0;
		while (crd.p_cols < area.p_cols)
		{
			pl = (!ft_strcmp(g_type, "X")) ? 'X' : 'O';
			if (map->field[crd.rows][crd.cols] == pl
				&& map->piece[crd.p_rows][crd.p_cols] == '*'
				&& crd.cols - crd.p_cols + area.p_cols <= area.cols &&
				crd.rows - crd.p_rows + area.p_rows <= area.rows &&
				crd.rows - crd.p_rows >= 0 && crd.cols - crd.p_cols >= 0)
			{
				tmp.rows = crd.rows - crd.p_rows;
				tmp.cols = crd.cols - crd.p_cols;
				if (!ft_if_cover_one(map->field, map->piece, tmp, area))
					ft_newnode(&(**pos_coord), crd.rows - crd.p_rows,
					crd.cols - crd.p_cols);
			}
			crd.p_cols++;
		}
		crd.p_rows++;
	}
}

void		ft_possible_coord(t_map *map, t_coord **pos_coord)
{
	t_coord crd;
	t_coord area;

	crd.cols = 0;
	crd.rows = 0;
	crd.p_cols = 0;
	crd.p_rows = 0;
	area = ft_count_area(map->field, map->piece);
	while (crd.rows < area.rows)
	{
		crd.cols = 0;
		while (crd.cols < area.cols)
		{
			crd.p_rows = 0;
			ft_possible_coord2(area, crd, map, &pos_coord);
			crd.cols++;
		}
		crd.rows++;
	}
	if (*pos_coord == NULL)
		ft_newnode(&(*pos_coord), 0, 0);
}

/*
*************************************************
**											   **
**			FINDING OPPONENT LAST PEACE	 	   **
**											   **
*************************************************
*/

t_coord		*opp_last_peace(char **field_map, char **map_dup,
								t_coord *map, char *g_type)
{
	t_coord *c;

	c = (t_coord*)malloc(sizeof(t_coord));
	c->cols = 0;
	c->rows = 0;
	if (map_dup != NULL)
	{
		while (c->rows < map->rows)
		{
			c->cols = 0;
			while (c->cols++ < map->cols)
			{
				if (!ft_strcmp(g_type, "O"))
					if (map_dup[c->rows][c->cols] == '.' &&
						field_map[c->rows][c->cols] == 'X')
						return (c);
				if (!ft_strcmp(g_type, "X"))
					if (map_dup[c->rows][c->cols] == '.' &&
						field_map[c->rows][c->cols] == 'O')
						return (c);
			}
			c->rows++;
		}
	}
	return (c);
}
