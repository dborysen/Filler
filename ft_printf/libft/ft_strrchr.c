/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:39:05 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/15 18:00:33 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *k;

	k = (char*)s + ft_strlen(s);
	while (*k != c)
		if (k-- == s)
			return (NULL);
	return (k);
}
