/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:51:09 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 19:39:05 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*s2;

	i = 0;
	l = 0;
	while (s1[l])
		l++;
	s2 = (char*)malloc(sizeof(char) * (l + 1));
	if (s2 == 0)
		return (0);
	while (i < l)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
