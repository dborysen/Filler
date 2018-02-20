/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_alignment_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:16:50 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 15:16:51 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_part_u(t_flags *flags, unsigned long long argptr, int n)
{
	int zero_num;

	zero_num = flags->precision - ft_count_digit_u(argptr);
	if (flags->plus == '+')
		flags->bnum += ft_putchar('+');
	else if (flags->space == ' ')
		flags->bnum += ft_putchar(' ');
	while (n++ < zero_num)
		flags->bnum += ft_putchar('0');
	flags->bnum += ft_putllu(argptr);
	n = 0;
	if (flags->width > flags->precision)
	{
		if (flags->plus == '+' || flags->space == ' ')
			n++;
		while (n++ < (flags->width - flags->precision))
			flags->bnum += ft_putchar(' ');
	}
}

void	left_alignment_u(t_flags *flags, unsigned long long argptr)
{
	int n;

	n = 0;
	if (flags->precision != 0)
		precision_part_u(flags, argptr, n);
	else
	{
		if (flags->plus == '+' || flags->space == ' ')
			flags->width = flags->width - 1;
		if (flags->plus == '+')
			flags->bnum += ft_putchar('+');
		else if (flags->space == ' ')
			flags->bnum += ft_putchar(' ');
		flags->bnum += ft_putllu(argptr);
		while (n++ < (flags->width - ft_count_digit_u(argptr)))
			flags->bnum += ft_putchar(' ');
	}
}
