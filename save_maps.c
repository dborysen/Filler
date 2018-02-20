/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:12:15 by dborysen          #+#    #+#             */
/*   Updated: 2018/02/14 13:12:16 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
*************************************************
**											   **
**			FINDING OPTIMAL COORDINATES	 	   **
**											   **
*************************************************
*/

int			ft_modul(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_coord		*get_right_coord(t_coord *head, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_coord		*find_pos_coord(t_coord *head, t_coord *op)
{
	t_coord	*tmp;
	int		dist;
	int		dist_fin;
	int		n;
	int		i;

	dist_fin = 100000000;
	i = 0;
	tmp = head;
	while (tmp != NULL)
	{
		dist = ft_modul(op->cols - tmp->cols) + ft_modul(op->rows - tmp->rows);
		if (dist < dist_fin)
		{
			dist_fin = dist;
			n = i;
		}
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = head;
	return (get_right_coord(tmp, n));
}

/*
*************************************************
**											   **
**	 SAVING THE FIELD IN TWO DEMENTION ARRAY   **
**											   **
*************************************************
*/

char		**field_save(t_coord *area, t_coord **last_coord,
				char ***field_dup, char **line)
{
	char	**field_map;
	int		i;

	field_map = (char**)malloc(sizeof(char*) * (area->rows + 1));
	field_map[area->rows] = 0;
	i = 0;
	while (i < area->rows)
	{
		get_next_line(0, line);
		field_map[i] = ft_strdup(*line + 4);
		free(*line);
		i++;
	}
	*last_coord = opp_last_peace(field_map, *field_dup, area, g_type);
	if (*field_dup != NULL)
	{
		i = 0;
		while ((*field_dup)[i])
			free((*field_dup)[i++]);
		free(*field_dup);
	}
	*field_dup = field_map;
	get_next_line(0, line);
	return (field_map);
}

/*
*************************************************
**
**	 SAVING THE PIECE IN TWO DEMENTION ARRAY
**
*************************************************
*/

char		**piece_save(t_coord *area)
{
	char *line;
	char **piece_map;

	g_i = 0;
	piece_map = (char**)malloc(sizeof(char*) * (area->p_rows + 1));
	piece_map[area->p_rows] = 0;
	while (g_i < area->p_rows)
	{
		get_next_line(0, &line);
		piece_map[g_i] = ft_strdup(line);
		free(line);
		g_i++;
	}
	return (piece_map);
}
