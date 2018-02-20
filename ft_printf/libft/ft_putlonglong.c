/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:40:58 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/02 12:40:59 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putlonglong(long long n)
{
	unsigned int k;

	k = 0;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n / 10)
		k = ft_putlonglong(n / 10);
	k = k + ft_putchar(n % 10 + '0');
	return (k);
}
