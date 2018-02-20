/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:57:21 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:38:54 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	l;

	l = 0;
	if (s == NULL)
		return (NULL);
	while (s[l++])
		;
	if (start > l - 2)
		return (0);
	l = 0;
	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (fresh == 0)
		return (NULL);
	while (len--)
		fresh[l++] = s[start++];
	fresh[l] = '\0';
	return (fresh);
}
