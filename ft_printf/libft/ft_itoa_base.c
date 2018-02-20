/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:00:12 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/27 14:00:13 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_base(unsigned long long v, int base)
{
	char	*baseline;
	char	*result;
	int		i;
	int		tmp;

	i = 0;
	tmp = v;
	baseline = ft_strdup("0123456789ABCDEF");
	while ((tmp / base) && (tmp /= base))
		i++;
	if ((result = (char*)malloc(sizeof(char) * (i + 2))) == 0)
		return (NULL);
	i = 0;
	while (v / base > 0)
	{
		(v % base < 10) ? (result[i++] = v % base + 48) :
		(result[i++] = baseline[v % base]);
		v = v / base;
	}
	(v < 10) ? result[i++] = (v % base + 48) :
	(result[i++] = baseline[v]);
	result[i] = '\0';
	ft_reverse(result);
	free(baseline);
	return (result);
}
