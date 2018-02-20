/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:03:54 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:52:07 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == 0)
		return (NULL);
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(sizeof(content[0]) * content_size);
		if (new->content == NULL)
		{
			free(new);
			return (0);
		}
		new->content = ft_memcpy(new->content, (void*)content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
