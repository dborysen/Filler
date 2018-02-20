/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:12:49 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 18:43:46 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstdp;
	t_list *lstnew;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	lstdp = f(lst);
	lstnew = ft_lstnew(lstdp->content, lstdp->content_size);
	if (!lstnew)
		return (NULL);
	first = lstnew;
	lst = lst->next;
	while (lst)
	{
		lstdp = f(lst);
		lstnew->next = ft_lstnew(lstdp->content, lstdp->content_size);
		if (!lstnew)
			return (NULL);
		lstnew = lstnew->next;
		lst = lst->next;
	}
	return (first);
}
