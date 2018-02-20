/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:04:28 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/26 11:50:37 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;
	t_list *l;

	l = *alst;
	if (alst && del)
	{
		while (l)
		{
			t = l->next;
			del(l->content, l->content_size);
			free(l);
			l = t;
		}
		*alst = NULL;
	}
}
