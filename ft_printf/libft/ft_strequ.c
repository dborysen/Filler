/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:21:00 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:33:05 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char *a1;
	char *a2;

	if (!s1 || !s2)
		return (0);
	a1 = ft_strdup(s1);
	a2 = ft_strdup(s2);
	if (!ft_strcmp(a1, a2))
		return (1);
	return (0);
}
