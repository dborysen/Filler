/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_alignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:25:41 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 14:25:42 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extra_sign(t_flags *flags, long long argptr)
{
	int n;
	int zero_num;

	n = 0;
	zero_num = 0;
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit(argptr);
	flags->width = flags->width - 1;
	if ((flags->zero == '0' || flags->precision != 0) && argptr < 0)
		flags->bnum += ft_putchar('-');
	else if (flags->zero == '0' && flags->plus == '+')
		flags->bnum += ft_putchar('+');
	else if (flags->zero == '0' && flags->space == ' ')
		flags->bnum += ft_putchar(' ');
	else if (flags->zero != '0' && argptr < 0)
		flags->bnum++;
	else if (flags->zero != '0' && flags->space == ' ' && flags->plus != '+')
		flags->bnum += ft_putchar(' ');
}

void	kostil_right(t_flags *flags, long long argptr)
{
	int n;
	int temp;
	int zero_num;

	n = 0;
	zero_num = 0;
	if (argptr < 0)
		temp = 1;
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit(argptr);
	if (flags->zero != '0' && flags->plus == '+' && temp != 1)
		flags->bnum += ft_putchar('+');
	if (flags->precision != 0)
	{
		while (n++ < zero_num)
			flags->bnum += ft_putchar('0');
		flags->bnum += ft_putlonglong(argptr);
	}
	else
		flags->bnum += ft_putlonglong(argptr);
}

void	right_alignment_d(t_flags *flags, long long argptr)
{
	int n;
	int temp;
	int zero_num;

	temp = 0;
	zero_num = 0;
	n = 0;
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit(argptr);
	if (argptr < 0)
		temp = 1;
	if (flags->plus == '+' || argptr < 0 || flags->space == ' ')
	{
		extra_sign(flags, argptr);
		if ((flags->zero == '0' || flags->precision != 0) && argptr < 0)
			argptr = -argptr;
	}
	while (n++ < (flags->width - ft_count_digit(argptr) - zero_num))
	{
		if (flags->zero != '0' || flags->precision != 0)
			flags->bnum += ft_putchar(' ');
		else if (flags->precision == 0)
			flags->bnum += ft_putchar('0');
	}
	kostil_right(flags, argptr);
}
