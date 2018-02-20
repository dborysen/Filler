/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_alignment_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:14:26 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/19 11:14:27 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_part_o(t_flags *flags, char *argptr, int n)
{
	int zero_num;
	int m;

	m = 0;
	if (flags->hash == '#')
	{
		m = 1;
		flags->bnum += ft_putstr("0");
	}
	zero_num = flags->precision - ft_strlen((char*)argptr);
	while (n++ < zero_num)
		flags->bnum += ft_putchar('0');
	flags->bnum += ft_putstr(argptr);
	n = 0;
	if (flags->width > flags->precision)
	{
		if (flags->plus == '+' || flags->space == ' ')
			n++;
		while (n++ < (flags->width - flags->precision - m))
			flags->bnum += ft_putchar(' ');
	}
}

void	left_alignment_o(t_flags *flags, char *argptr)
{
	int n;
	int m;

	n = 0;
	m = 0;
	if (flags->hash == '#')
		m = 1;
	if (flags->precision != 0)
		precision_part_o(flags, argptr, n);
	else
	{
		if (flags->plus == '+' || flags->space == ' ')
			flags->width = flags->width - 1;
		if (flags->hash == '#')
			flags->bnum += ft_putstr("0");
		flags->bnum += ft_putstr(argptr);
		while ((unsigned long)n++ < (flags->width -
		ft_strlen((char*)argptr)) - m)
			flags->bnum += ft_putchar(' ');
	}
}

void	precision_part_x(t_flags *flags, char *argptr, int n)
{
	int zero_num;
	int m;

	m = 0;
	if (flags->hash == '#')
	{
		m = 2;
		flags->bnum += ft_putstr("0x");
	}
	zero_num = flags->precision - ft_strlen((char*)argptr);
	while (n++ < zero_num)
		flags->bnum += ft_putchar('0');
	flags->bnum += ft_putstr(argptr);
	n = 0;
	if (flags->width > flags->precision)
	{
		if (flags->plus == '+' || flags->space == ' ')
			n++;
		while (n++ < (flags->width - flags->precision - m))
			flags->bnum += ft_putchar(' ');
	}
}

void	left_alignment_x(t_flags *flags, char *argptr)
{
	int n;
	int m;

	n = 0;
	m = 0;
	if (flags->hash == '#')
		m = 2;
	if (flags->precision != 0)
		precision_part_x(flags, argptr, n);
	else
	{
		if (flags->plus == '+' || flags->space == ' ')
			flags->width = flags->width - 1;
		if (flags->hash == '#')
			flags->bnum += ft_putstr("0x");
		flags->bnum += ft_putstr(argptr);
		while ((unsigned long)n++ < (flags->width -
		ft_strlen((char*)argptr)) - m)
			flags->bnum += ft_putchar(' ');
	}
}
