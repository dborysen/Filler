/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:08:37 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:20:51 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	i = 0;
	fresh = NULL;
	if (s && f)
	{
		fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!fresh)
			return (NULL);
		while (*(s + i))
		{
			*(fresh + i) = f(*(s + i));
			i++;
		}
		*(fresh + i) = '\0';
		return (fresh);
	}
	return (0);
}
