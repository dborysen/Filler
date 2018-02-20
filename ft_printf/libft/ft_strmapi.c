/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:49:20 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:55:12 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*fresh;

	i = 0;
	fresh = NULL;
	if (s && f)
	{
		fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (fresh == 0)
			return (NULL);
		while (*(s + i))
		{
			*(fresh + i) = f(i, *(s + i));
			i++;
		}
		*(fresh + i) = '\0';
		return (fresh);
	}
	return (0);
}
