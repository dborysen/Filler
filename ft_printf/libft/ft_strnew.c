/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:15:26 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/16 14:22:34 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	fresh = (char*)malloc(size + 1);
	if (fresh == 0)
		return (NULL);
	ft_memset(fresh, '\0', size + 1);
	return (fresh);
}
