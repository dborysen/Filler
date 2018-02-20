/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:34:08 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/16 11:12:18 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (!*lit)
		return ((char*)big);
	while (i < len && big[i])
	{
		j = 0;
		while (lit[j] == big[j + i] && (i + j < len))
		{
			if (lit[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
