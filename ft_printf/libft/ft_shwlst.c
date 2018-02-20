/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shwlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:20:03 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/26 11:44:49 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_shwlst(t_list *alst)
{
	t_list *blst;

	blst = alst;
	while (blst)
	{
		ft_putstr(blst->content);
		blst = blst->next;
		ft_putchar('\n');
	}
}
