/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:48:53 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/08 11:48:54 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putllu(unsigned long long n)
{
	unsigned int k;

	k = 0;
	if (n / 10)
		k = ft_putllu(n / 10);
	k = k + ft_putchar(n % 10 + '0');
	return (k);
}
