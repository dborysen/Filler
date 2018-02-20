/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:15:40 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 16:21:07 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countw(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	int		i;
	int		l;
	int		k;

	k = 0;
	fresh = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	i = countw(s);
	if ((l - i))
	{
		l -= 1;
		while (s[l] == ' ' || s[l] == '\t' || s[l] == '\n')
			l--;
		if (!(fresh = (char*)malloc(sizeof(char) * (l - i + 2))))
			return (NULL);
		while (i <= l)
			fresh[k++] = s[i++];
		fresh[k] = '\0';
		return (fresh);
	}
	return (ft_strdup("\0"));
}
