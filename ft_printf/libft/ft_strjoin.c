/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:00:29 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:43:51 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		l1;
	int		l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	fresh = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	if (fresh == 0)
		return (NULL);
	l1 = 0;
	l2 = 0;
	while (s1[l1] && (fresh[l1] = s1[l1]))
		l1++;
	while (s2[l2] && (fresh[l1++] = s2[l2++]))
		;
	fresh[l1] = '\0';
	return (fresh);
}
