/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:57:34 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 15:56:00 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lit)
{
	int i;
	int j;

	i = 0;
	if (!*lit)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (lit[j] == big[i + j])
		{
			if (lit[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
