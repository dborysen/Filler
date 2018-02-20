/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:01:27 by dborysen          #+#    #+#             */
/*   Updated: 2018/02/14 13:01:28 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_field_area(char **line, t_coord *field)
{
	if (ft_strstr(*line, "Plateau"))
	{
		field->rows = ft_atoi(*line + 8);
		field->cols = ft_atoi(*line + 11);
	}
	free(*line);
	get_next_line(0, line);
	free(*line);
}

void	ft_piece_area(char **line, t_coord *piece)
{
	if (ft_strstr(*line, "Piece"))
	{
		piece->p_rows = ft_atoi(*line + 6);
		piece->p_cols = ft_atoi(*line + 8);
	}
	free(*line);
}

void	ft_wich_g_type(char **line, char **g_type)
{
	if (ft_strstr(*line, "p1"))
		*g_type = "O";
	if (ft_strstr(*line, "p2"))
		*g_type = "X";
	free(*line);
}

void	ft_newnode(t_coord **head, int y, int x)
{
	t_coord *temp;
	t_coord *newnode;

	temp = *head;
	newnode = (t_coord*)malloc(sizeof(t_coord));
	newnode->rows = y;
	newnode->cols = x;
	newnode->next = NULL;
	if (temp == NULL)
		*head = newnode;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}

void	ft_lst_del(t_coord **head)
{
	t_coord *temp;
	t_coord *temp1;

	temp = *head;
	while (temp != NULL)
	{
		temp1 = temp->next;
		temp->cols = 0;
		temp->rows = 0;
		free(temp);
		temp = temp1;
	}
}
