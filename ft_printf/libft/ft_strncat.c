/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:39:33 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/15 17:39:40 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, const char *srcptr, size_t n)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(destptr);
	while (i < n && srcptr[i])
		destptr[l++] = srcptr[i++];
	destptr[l] = '\0';
	return (destptr);
}
