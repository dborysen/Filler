/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_alignment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:23:35 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 14:23:36 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_part(t_flags *flags, long long argptr, int n, int neg)
{
	int zero_num;

	zero_num = flags->precision - ft_count_digit(argptr);
	if (flags->plus == '+' && argptr > 0)
		flags->bnum += ft_putchar('+');
	else if (argptr < 0)
	{
		flags->bnum += ft_putchar('-');
		argptr = -argptr;
	}
	else if (flags->space == ' ')
		flags->bnum += ft_putchar(' ');
	while (n++ < zero_num)
		flags->bnum += ft_putchar('0');
	flags->bnum += ft_putlonglong(argptr);
	n = 0;
	if (flags->width > flags->precision)
	{
		if (neg == 1 || flags->plus == '+' || flags->space == ' ')
			n++;
		while (n++ < (flags->width - flags->precision))
			flags->bnum += ft_putchar(' ');
	}
}

void	left_alignment_d(t_flags *flags, long long argptr)
{
	int n;
	int neg;

	n = 0;
	neg = 0;
	if (argptr < 0)
		neg = 1;
	if (flags->precision != 0)
		precision_part(flags, argptr, n, neg);
	else
	{
		if (neg == 1 || flags->plus == '+' || flags->space == ' ')
			flags->width = flags->width - 1;
		if (flags->plus == '+' && argptr > 0)
			flags->bnum += ft_putchar('+');
		else if (flags->space == ' ' && argptr >= 0)
			flags->bnum += ft_putchar(' ');
		else if (neg == 1)
			flags->bnum++;
		flags->bnum += ft_putlonglong(argptr);
		while (n++ < (flags->width - ft_count_digit(argptr)))
			flags->bnum += ft_putchar(' ');
	}
}
