/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_alignment_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:18:44 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/19 11:18:45 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	kostil_right_o(t_flags *flags, char *argptr, int zero_num)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while ((unsigned long)n++ < (flags->width -
	ft_strlen((char*)argptr) - zero_num - m))
		if (flags->zero != '0' || flags->precision != 0)
			flags->bnum += ft_putchar(' ');
		else if (flags->precision == 0)
			flags->bnum += ft_putchar('0');
	if (flags->hash == '#')
		m = 1;
	if (flags->hash == '#' && flags->precision != 0)
		flags->bnum += ft_putstr("0");
	if (flags->precision != 0)
	{
		while (n++ < zero_num)
			flags->bnum += ft_putchar('0');
		flags->bnum += ft_putstr((char*)argptr);
	}
	else
		flags->bnum += ft_putstr((char*)argptr);
}

void	right_alignment_o(t_flags *flags, char *argptr)
{
	int n;
	int m;
	int zero_num;

	zero_num = 0;
	n = 0;
	m = 0;
	if (flags->hash == '#')
	{
		m = 1;
		if (flags->precision == 0 && ((unsigned long)flags->width
			< ft_strlen((char*)argptr) + m) && ft_strcmp(argptr, "0"))
			flags->bnum += ft_putstr("0");
	}
	if ((unsigned long)flags->width < ft_strlen((char*)argptr) + m)
	{
		flags->bnum += ft_putstr((char*)argptr);
		return ;
	}
	else if ((size_t)flags->precision >= ft_strlen((char*)argptr))
		zero_num = flags->precision - ft_strlen((char*)argptr);
	kostil_right_o(flags, argptr, zero_num);
}

void	kostil_right_x(t_flags *flags, char *argptr, int zero_num)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while ((unsigned long)n++ < (flags->width -
	ft_strlen((char*)argptr) - zero_num - m))
		if (flags->zero != '0' || flags->precision != 0)
			flags->bnum += ft_putchar(' ');
		else if (flags->precision == 0)
			flags->bnum += ft_putchar('0');
	if (flags->hash == '#')
		m = 2;
	if (flags->hash == '#' && flags->precision != 0)
		flags->bnum += ft_putstr("0x");
	if (flags->precision != 0)
	{
		while (n++ < zero_num)
			flags->bnum += ft_putchar('0');
		flags->bnum += ft_putstr((char*)argptr);
	}
	else
		flags->bnum += ft_putstr((char*)argptr);
}

void	right_alignment_x(t_flags *flags, char *argptr)
{
	int n;
	int m;
	int zero_num;

	zero_num = 0;
	n = 0;
	m = 0;
	if (flags->hash == '#')
	{
		m = 2;
		if (flags->precision == 0 && ((unsigned long)flags->width
			< ft_strlen((char*)argptr) + m) && ft_strcmp(argptr, "0"))
			flags->bnum += ft_putstr("0x");
	}
	if ((unsigned long)flags->width < ft_strlen((char*)argptr) + m)
	{
		flags->bnum += ft_putstr((char*)argptr);
		return ;
	}
	else if ((size_t)flags->precision >= ft_strlen((char*)argptr))
		zero_num = flags->precision - ft_strlen((char*)argptr);
	kostil_right_x(flags, argptr, zero_num);
}
