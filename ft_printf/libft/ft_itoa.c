/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:20:32 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/17 16:45:39 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	isneg(int n)
{
	if (n < 0)
		return (3);
	return (2);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	int		i;
	int		dub;
	int		d;

	dub = n;
	d = isneg(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (d == 3)
		n = -n;
	while ((dub / 10) && (dub /= 10))
		i++;
	if ((fresh = (char*)malloc(sizeof(char) * (i + d))) == 0)
		return (NULL);
	i = 0;
	while (n / 10 && (fresh[i++] = n % 10 + 48) && (n /= 10))
		;
	fresh[i++] = n % 10 + 48;
	if (d == 3)
		fresh[i++] = '-';
	fresh[i] = '\0';
	ft_reverse(fresh);
	return (fresh);
}
